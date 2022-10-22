#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#define inf 0x3f3f3f3f
#define met(a,b) memset(a,b,sizeof a)
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 2e7+10;
int sz[N],lson[N],rson[N],num[N],bit[N],n,total;
int addson() {return ++total;}
int lowbit(int x) {return x&(-x);}
void add(int &x,int l,int r,int y,int z){
    if (!x)x=addson();
    sz[x]+=z;
    if (l==r) return;
    int mid=(l+r)>>1;
    if (y<=mid) add(lson[x],l,mid,y,z);
    else add(rson[x],mid+1,r,y,z);
}
int ask(int x,int l,int r,int y){
    if (!x) return 0;
    if (l==r) return sz[x];
    int mid=(l+r)>>1;
    if (y<=mid) return ask(lson[x],l,mid,y);
    else return sz[lson[x]]+ask(rson[x],mid+1,r,y);
}
ll bigask(int x,int y){
    ll now=0;
    while (x) {
        now+=ask(bit[x],1,n,y);
        x-=lowbit(x);
    }
    return now;
}
void bigadd(int x,int y,int z){
    while (x<=n) {
        add(bit[x],1,n,y,z);
        x+=lowbit(x);
    }
}
int main(){
    int m;
    scanf("%d%d",&n,&m);
    ll sum=0;
    for(int i=1;i<=n;i++)bigadd(i,num[i]=i,1);
    while (m--) {
        int l,r;
        scanf("%d %d",&l,&r);
        if (l==r) {
            printf("%lld\n",sum);
            continue;
        }
        if (l>r)swap(l,r);
        if (r-l>1) {
            sum-=2*(bigask(r-1,num[l])-bigask(l,num[l]));
            sum+=2*(bigask(r-1,num[r])-bigask(l,num[r]));
        }
        if (num[l]<num[r]) ++sum;
        else --sum;
        printf("%lld\n",sum);
        bigadd(l,num[l],-1);
        bigadd(l,num[r],1);
        bigadd(r,num[r],-1);
        bigadd(r,num[l],1);
        swap(num[l],num[r]);
    }
    return 0;
}