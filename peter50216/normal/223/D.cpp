// @author peter50216
// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<limits.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
// }}}
struct XD{
    double x,y;
    int id;
    XD(double xx=0,double yy=0):x(xx),y(yy){}
    void get(int ii){
        id=ii;
        scanf("%lf%lf",&x,&y);
    }
    XD operator-(const XD& b)const{
        return XD(x-b.x,y-b.y);
    }
    XD operator-()const{
        return XD(-x,-y);
    }
    double operator*(const XD& b)const{
        return x*b.x+y*b.y;
    }
    double operator^(const XD& b)const{
        return x*b.y-y*b.x;
    }
    int ss()const{
        return x>0||(x>=-1e-9&&y>0);
    }
    bool operator<(const XD& b)const{
        if(ss()!=b.ss())return ss()<b.ss();
        return ((*this)^b)<0;
    }
    void print(const char* c){printf("%s: %.3lf %.3lf\n",c,x,y);}
    double len(){return sqrt(x*x+y*y);}
};
const double eps=1e-7;
bool cmpx(const XD& a,const XD& b){
    return a.x==b.x?a.y<b.y:a.x<b.x;
}
bool cmpy(const XD& a,const XD& b){
    return a.y==b.y?a.x<b.x:a.y<b.y;
}
XD in[101000];
double nowx;
struct line{
    int a,b,id;
    line(){}
    line(int aa,int bb,int ii):a(aa),b(bb),id(ii){
        if(cmpx(in[b],in[a]))swap(a,b);
    }
    double get(double x)const{
        if(in[a].x==in[b].x)return in[b].y;
        return ((x-in[a].x)*in[b].y+(in[b].x-x)*in[a].y)/((double)in[b].x-in[a].x);
    }
    bool isv()const{
        return fabs(in[a].x-in[b].x)<eps;
    }
    bool isin(double x)const{
        return x>=in[a].x&&x<=in[b].x;
    }
    bool operator<(const line& x)const{
        double x1=get(nowx),x2=x.get(nowx);
        if(fabs(x1-x2)<eps){
            if(x.isv())return 0;
            if(isv())return 1;
            double n1=nowx-1e-4,n2=nowx+1e-4;
            if(isin(n1)&&x.isin(n1))return get(n1)<x.get(n1);
            else if(isin(n2)&&x.isin(n2))return get(n2)<x.get(n2);
            else return id<x.id;
        }
        return x1<x2;
    }
    void print()const{
        in[a].print("a");
        in[b].print("b");
    }
};
line lns[101000];
struct ev{
    int ln;
    int isin;
    ev(){}
    ev(int ll,int ii):ln(ll),isin(ii){}
    int pt()const{
        if(isin)return lns[ln].a;
        else return lns[ln].b;
    }
    bool operator<(const ev& b)const{
        int p1=pt(),p2=b.pt();
        if(in[p1].x==in[p2].x)return isin>b.isin;
        return cmpx(in[p1],in[p2]);
    }
};
ev evs[201000];
struct ee{
    int y;
    double l;
    ee(int yy=0,double ll=0):y(yy),l(ll){}
};
vector<ee> ed[101000];
bool hasd[101000];
bool hasu[101000];
int que[101000],qs,qe;
double dis[101000];
bool inq[101000];
int n;
inline void push(int x){
    if(inq[x])return;
    inq[x]=1;
    que[qe++]=x;
    if(qe==101000)qe=0;
}
inline int pop(){
    int a=que[qs++];
    if(qs==101000)qs=0;
    inq[a]=0;
    return a;
}
inline double spfa(int st,int end){
    int i;
    for(i=0;i<n;i++)dis[i]=1e100;
    dis[st]=0;
    qs=qe=0;
    push(st);
    while(qs!=qe){
        int np=pop();
        for(i=0;i<ed[np].size();i++){
            int y=ed[np][i].y;
            double l=ed[np][i].l;
            if(dis[y]>dis[np]+l){
                dis[y]=dis[np]+l;
                push(y);
            }
        }
    }
    return dis[end];
}
int main(){
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++){
        in[i].get(i);
    }
    for(i=0;i<n;i++){
        int ii=(i+1==n?0:i+1);
        double d=(in[i]-in[ii]).len();
        ed[i].push_back(ee(ii,d));
        ed[ii].push_back(ee(i,d));
    }
    for(i=0;i<n;i++){
        int p1=(i==0?n-1:i-1);
        int p2=(i==n-1?0:i+1);
        XD l1=in[p1]-in[i];
        XD l2=in[p2]-in[i];
        XD b(0,-1);
        if((l1.x==0&&l1.y<0)||(l2.x==0&&l2.y<0))hasd[i]=0;
        else if(l2<l1)hasd[i]=1;
        else hasd[i]=0;
        if((l1.x==0&&l1.y>0)||(l2.x==0&&l2.y>0))hasu[i]=0;
        else if(-l2<-l1)hasu[i]=1;
        else hasu[i]=0;
//        printf("hasd[%d] = %d %d\n",i,hasd[i],hasu[i]);
    }
    int ec=0;
    for(i=0;i<n;i++){
        int ii=(i+1==n?0:i+1);
        lns[i]=line(i,ii,i);
        evs[ec++]=ev(i,0);
        evs[ec++]=ev(i,1);
    }
    sort(evs,evs+ec);
    multiset<line> ss;
    for(i=0;i<ec;i++){
        int id=evs[i].ln;
        int isin=evs[i].isin;
        int p=evs[i].pt();
        nowx=in[p].x;
        if(hasd[p]||hasu[p]){
            multiset<line>::iterator i2;
//            for(i2=ss.begin();i2!=ss.end();i2++)i2->print();
//            puts("-----------");
            multiset<line>::iterator it=ss.lower_bound(line(p,p,-1));
            if(hasu[p]){
                i2=it;
                while(i2!=ss.end()&&i2->get(nowx)<in[p].y+eps)i2++;
                if(i2!=ss.end()){
                    double y=i2->get(nowx);
//                    in[i2->a].print("a");
//                    in[i2->b].print("b");
//                    printf("p=%d nowx=%d y=%.3lf\n",p,nowx,y);
                    if(y>in[p].y+eps){
                        double d=y-in[p].y;
                        XD pp(nowx,y);
                        ed[i2->a].push_back(ee(p,d+(in[i2->a]-pp).len()));
                        ed[i2->b].push_back(ee(p,d+(in[i2->b]-pp).len()));
                    }
                }
            }
            if(hasd[p]&&it!=ss.begin()){
                i2=it;
                i2--;
                while(i2!=ss.begin()&&i2->get(nowx)>in[p].y-eps)i2--;
                double y=i2->get(nowx);
//                in[i2->a].print("a");
//                in[i2->b].print("b");
                //printf("p=%d nowx=%d y=%.3lf\n",p,nowx,y);
                if(y<in[p].y-eps){
                    double d=in[p].y-y;
                    XD pp(nowx,y);
                    ed[p].push_back(ee(i2->a,d+(in[i2->a]-pp).len()));
                    ed[p].push_back(ee(i2->b,d+(in[i2->b]-pp).len()));
                }
            }
        }
//        printf("i=%d p=%d %s %d\n",i,p,isin?"add":"remove",id);
        if(isin){
            ss.insert(lns[id]);
        }else{
            ss.erase(lns[id]);
        }
    }
    /*
    for(i=0;i<n;i++){
        printf("%d: ",i);
        for(int j=0;j<ed[i].size();j++)printf("(%d,%.3lf) ",ed[i][j].y,ed[i][j].l);
        puts("");
    }*/
    int start,end;
    scanf("%d%d",&start,&end);start--;end--;
    printf("%.9lf\n",spfa(start,end));
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread