#include <cstdio>
#include <algorithm>
#include <set>
#define l first
#define r second

using namespace std;

typedef long long ll;

pair<ll,ll> br[200010];

struct gap {
    int i;
    ll l,r;
    bool operator<(const gap& other) const {
        return br[i+1].r-br[i].l < br[other.i+1].r-br[other.i].l;
    }
} gap[200010];

pair<ll,int> bl[200010];
int n,m;

int ans[200010];

int main()
{
    scanf("%d%d",&n,&m);
    if(n-1 > m){
        puts("No");
        return 0;
    }
    int i;
    for(i=0;i<n;++i){
        scanf("%I64d%I64d",&br[i].l,&br[i].r);
        if(i!=n-1){
            gap[i].i=i;
            gap[i].l=br[i].r;
        }
        if(i!=0){
            gap[i-1].r=br[i].l;
        }
    }
    sort(gap,gap+n-1);
    multiset<pair<long long,int> > bl;
    ll ba;
    for(i=0;i<m;++i) scanf("%I64d",&ba), bl.insert({ba,i});
    int ind;
    ll ll_,lr,rl,rr;
    multiset<pair<long long,int> >::iterator it;
    for(i=0;i<n-1;++i){
        ind=gap[i].i;
        ll_=br[ind  ].l; lr=br[ind  ].r;
        rl=br[ind+1].l; rr=br[ind+1].r;
        if((it=bl.lower_bound({gap[i].r-gap[i].l,0}))!=bl.end()){
            if(rl<=lr+it->first && ll_+it->first<=rr){
                ans[ind]=it->second;
                bl.erase(it);
            } else {
                puts("No"); return 0;
            }
        } else {
            puts("No"); return 0;
        }
    }
    puts("Yes");
    for(i=0;i<n-1;++i) printf("%d ",ans[i]+1);
    return 0;
}