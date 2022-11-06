#include <cstdio>
#include <set>

using namespace std;
typedef long long ll;
int sqr=710;
multiset<ll> buck[710];
ll buckupd[710];
int n,q;
int data[500010];
void upd(int l,int r,int x){
    while(l<=r){
        if(l%sqr==0 && l+sqr-1<=r){
            buckupd[l/sqr]+=x;
            l+=sqr;
        } else {
            int bi=l/sqr;
            ll bef=data[l];
            buck[bi].erase(buck[bi].find(bef));
            data[l]+=x;
            buck[bi].insert(data[l]);
            //printf("updating value at %d\n",l);
            ++l;
        }
    }
}
int findLind(ll x){
    int i;
    for(i=0;i<sqr;++i){
        if(i*sqr>n) break;
        if(buck[i].find(x-buckupd[i])!=buck[i].end()) return i;
    }
    return -1;
}
int findRind(ll x){
    int i;
    for(i=sqr-1;i>=0;--i){
        if(i*sqr>n) continue;
        if(buck[i].find(x-buckupd[i])!=buck[i].end()) return i;
    }
    return -1;
}
int findRealindL(int cb,ll x){
    //printf("cb %d, x %I64d\n",cb,x);
    int i;
    ll targval=x-buckupd[cb];
    for(i=0;i<sqr;++i){
        if(data[cb*sqr+i]==targval) return cb*sqr+i;
    }
}
int findRealindR(int cb,ll x){
    //printf("cb %d, x %I64d\n",cb,x);
    int i;
    ll targval=x-buckupd[cb];
    for(i=sqr-1;0<=i;--i){
        if(cb*sqr+i<=n && data[cb*sqr+i]==targval) return cb*sqr+i;
    }
}

int main()
{
    scanf("%d%d",&n,&q);
    int i;
    for(i=1;i<=n;++i) scanf("%d",data+i), buck[i/sqr].insert(data[i]);
    int cmd;
    int l,r,x;
    for(;q--;){
        scanf("%d",&cmd);
        if(cmd==1){
            scanf("%d%d%d",&l,&r,&x);
            upd(l,r,x);
        } else {
            scanf("%d",&x);
            l=findLind(x);
            if(l==-1) printf("%d\n",-1);
            else printf("%d\n",findRealindR(findRind(x),x)-findRealindL(l,x));
        }
    }
    return 0;
}