#include<bits/stdc++.h>
//#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define x first
#define y second
struct kth_heap{
    priority_queue<pii> p1;
    priority_queue<pii,vector<pii>,greater<pii> > p2;
    int T,slz;
    void push(int x,int y){
        T+=x;
        p1.push(make_pair(x,y));
        if(p1.size()>slz){
            T-=p1.top().x;
            p2.push(p1.top());
            p1.pop();
        }
    }
    int get(){return T;}
    void Addsize(){
        ++slz;
        if(!p2.empty()){
            T+=p2.top().x;
            p1.push(p2.top());
            p2.pop();
        }
    }
    void Remsize(){
        --slz;
        if(p1.size()>slz){
            T-=p1.top().x;
            p2.push(p1.top());
            p1.pop();
        }
    }
    int full(){
    //    printf("%d %d\n",p1.size(),slz);
        return p1.size()==slz;
    }
    void Write(){
        while(!p1.empty()){
            printf("%d ",p1.top().y);
            p1.pop();
        }
    }
};
kth_heap p;
struct Task{
    int a,t,id;
};
Task a[202424];
int cmp(Task a,Task b){
    return a.a>b.a;
}
int main(){
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&a[i].a,&a[i].t);
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    int s=1;
    //for(int i=1;i<=n;++i)printf("%d\n",a[i].a);
    for(int i=0;i<=n;++i)p.Addsize();
    int ans=0;
    for(int i=n;i>=1;--i){
        p.Remsize();
        while(s<=n&&a[s].a>=i){
            p.push(a[s].t,a[s].id);
            ++s;
        }
    //    printf("%d!!!\n",p.get());
        if(p.full()&&(p.get()<=t)){
            printf("%d\n%d\n",i,i);
            p.Write();
            return 0;
        }
    }
    printf("0\n0\n\n");
    return 0;
}