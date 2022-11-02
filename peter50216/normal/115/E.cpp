#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
inline long long max(long long a,long long b){return a>b?a:b;}
long long tre[2][1050000];
long long tt[2][1050000];
long long sa[2][1050000];
long long sp[210000];
long long rp[210000];
const long long INF=1000000000000000000ll;
bool debug=0;
struct XD{
    long long l,r;
    long long p;
    void get(){
	scanf("%I64d%I64d%I64d",&l,&r,&p);
    }
    void print(){
	fprintf(stdout,"%d %d %I64d\n",l,r,p);
    }
    bool operator<(const XD& b)const{
	return l==b.l?r>b.r:l<b.l;
    }
}in[210000];
inline void fill(int q,long long l,long long r,long long np,long long val){
    if(np>600000)puts("!");
    tre[q][np]=val;
    tt[q][np]=val;
    sa[q][np]=0;
    if(l==r)return;
    long long m=(l+r)/2;
    fill(q,l,m,np*2,val);
    fill(q,m+1,r,np*2+1,val);
}
inline void add(int q,long long l,long long r,long long np,long long c,long long val){
    if(np>600000)puts("!");
    if(l==r){
	tre[q][np]=max(tre[q][np]+sa[q][np],val);
	if(tre[q][np]!=val)puts("!");
	tt[q][np]=max(tt[q][np]+sa[q][np],val+sp[l]);
	if(tt[q][np]!=val+sp[l])puts("!");
	sa[q][np]=0;
	return;
    }
    if(l>=r)while(1);
    sa[q][np*2]+=sa[q][np];
    sa[q][np*2+1]+=sa[q][np];
    sa[q][np]=0;
    long long m=(l+r)/2;
    if(c<=m)add(q,l,m,np*2,c,val);
    else add(q,m+1,r,np*2+1,c,val);
    tre[q][np]=max(tre[q][np*2]+sa[q][np*2],tre[q][np*2+1]+sa[q][np*2+1]);
    tt[q][np]=max(tt[q][np*2]+sa[q][np*2],tt[q][np*2+1]+sa[q][np*2+1]);
}
inline void add(int q,long long l,long long r,long long np,long long x,long long y,long long val){
    if(np>600000)puts("!");
    if(l==x&&r==y){
	sa[q][np]+=val;
	return;
    }
    if(l>=r||l>x||r<y)while(1);
    sa[q][np*2]+=sa[q][np];
    sa[q][np*2+1]+=sa[q][np];
    sa[q][np]=0;
    long long m=(l+r)/2;
    if(x<=m&&y>m){
	add(q,l,m,np*2,x,m,val);
	add(q,m+1,r,np*2+1,m+1,y,val);
    }else if(x>m)add(q,m+1,r,np*2+1,x,y,val);
    else add(q,l,m,np*2,x,y,val);
    tre[q][np]=max(tre[q][np*2]+sa[q][np*2],tre[q][np*2+1]+sa[q][np*2+1]);
    tt[q][np]=max(tt[q][np*2]+sa[q][np*2],tt[q][np*2+1]+sa[q][np*2+1]);
}
inline long long qu1(int q,long long l,long long r,long long x,long long y,long long np){
    if(np>600000)puts("!");
    if(l==x&&r==y){
	return tre[q][np]+sa[q][np];
    }
    if(l>=r||l>x||r<y)while(1);
    if(l>=r)while(1);
    sa[q][np*2]+=sa[q][np];
    sa[q][np*2+1]+=sa[q][np];
    tre[q][np]+=sa[q][np];
    tt[q][np]+=sa[q][np];
    sa[q][np]=0;
    long long m=(l+r)/2;
    if(x<=m&&y>m){
	return max(qu1(q,l,m,x,m,np*2),qu1(q,m+1,r,m+1,y,np*2+1));
    }else if(x>m){
	return qu1(q,m+1,r,x,y,np*2+1);
    }else{
	return qu1(q,l,m,x,y,np*2);
    }
}
inline long long qu2(int q,long long l,long long r,long long x,long long y,long long np){
    if(np>600000)puts("!");
    if(l==x&&r==y){
	return tt[q][np]+sa[q][np];
    }
    if(l>=r||l>x||r<y)while(1);
    if(l>=r)while(1);
    sa[q][np*2]+=sa[q][np];
    sa[q][np*2+1]+=sa[q][np];
    tre[q][np]+=sa[q][np];
    tt[q][np]+=sa[q][np];
    sa[q][np]=0;
    long long m=(l+r)/2;
    if(x<=m&&y>m){
	return max(qu2(q,l,m,x,m,np*2),qu2(q,m+1,r,m+1,y,np*2+1));
    }else if(x>m){
	return qu2(q,m+1,r,x,y,np*2+1);
    }else{
	return qu2(q,l,m,x,y,np*2);
    }
}
int main(){
    long long n,m,i;
    scanf("%I64d%I64d",&n,&m);
    sp[0]=0;
    for(i=1;i<=n;i++){
	scanf("%I64d",&rp[i]);
	sp[i]=sp[i-1]+rp[i];
    }
    for(i=0;i<m;i++)in[i].get();
    sort(in,in+m);
    //if(rp[1]==471902965&&n==200000)debug=1;
    if(debug)in[m-1].print();
    fill(0,0,n,1,-INF);
    add(0,0,n,1,0,0);
    fill(1,0,n,1,-INF);
    add(1,0,n,1,0,0);
    for(i=0;i<m;i++){
	long long f1=qu1(0,0,n,0,in[i].r,1)-(sp[in[i].r]-sp[in[i].l-1]);
	long long s1=qu2(0,0,n,in[i].l,in[i].r,1)-sp[in[i].r];
	//if(debug&&i%50000==49999)printf("%d %d %I64d f=%I64d s=%I64d\n",in[i].l,in[i].r,in[i].p,f,s);
	add(0,0,n,1,in[i].r,max(f1,s1));//+in[i].p);
	add(0,0,n,1,in[i].r,n,in[i].p);
	long long f2=qu1(1,0,n,0,in[i].r,1)-(sp[in[i].r]-sp[in[i].l-1]);
	long long s2=qu2(1,0,n,in[i].l,in[i].r,1)-sp[in[i].r];
	//if(debug&&i%50000==49999)printf("%d %d %I64d f=%I64d s=%I64d\n",in[i].l,in[i].r,in[i].p,f,s);
	add(1,0,n,1,in[i].r,max(f2,s2)+in[i].p);
	if(in[i].r<n)add(1,0,n,1,in[i].r+1,n,in[i].p);
	if(f1!=f2||s1!=s2){
	    printf("%I64d %I64d %I64d %I64d f=%I64d s=%I64d %I64d %I64d\n",i,in[i].l,in[i].r,in[i].p,f1,s1,f2,s2);
	}
    }
    printf("%I64d\n",qu1(0,0,n,0,n,1));
}