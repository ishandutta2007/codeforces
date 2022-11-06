#include <cstdio>
#include <algorithm>
#include <cmath>
#define l first
#define r second

int n,t;
int data[200010];
int cnt[1000010];
int sq;
using namespace std;
pair<int,int> q[200010];
int qi[200010];
long long ans[200010];
long long curans;
void add(int pos){
    int v=data[pos];
    curans-=1LL*v*cnt[v]*cnt[v];
    ++cnt[v];
    curans+=1LL*v*cnt[v]*cnt[v];
}
void pop(int pos){
    int v=data[pos];
    curans-=1LL*v*cnt[v]*cnt[v];
    --cnt[v];
    curans+=1LL*v*cnt[v]*cnt[v];
}
int main()
{
    scanf("%d%d",&n,&t); sq=n/sqrt(t)+1;
    int i;
    for(i=0;i<n;++i) scanf("%d",data+i+1);
    for(i=0;i<t;++i) scanf("%d%d",&q[i].l,&q[i].r),qi[i]=i;
    sort(qi,qi+t,[](const int& a,const int& b){return q[a].l/sq==q[b].l/sq?q[a].r<q[b].r:q[a].l<q[b].l; });
    int a=0,b=0;
    int cq;
    for(i=0;i<t;++i){
        cq=qi[i];
        while(a<q[cq].l) pop(a++);
        while(q[cq].l<a) add(--a);
        
        while(q[cq].r<b) pop(b--);
        while(b<q[cq].r) add(++b);
        ans[cq]=curans;
    }
    for(i=0;i<t;++i) printf("%I64d\n",ans[i]);
    return 0;
}