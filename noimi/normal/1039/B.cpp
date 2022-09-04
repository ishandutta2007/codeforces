
 #include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 200010
using namespace std;
bool check(ll x,ll y){
    printf("%lld %lld\n",x,y);
    string s;
    cin>>s;
    fflush(stdout);
    if(s=="Yes") return true;
    else return false;
}
main(){
    ll n,k;cin>>n>>k;
    ll l=1,r=n,a;
    while(r-l+1>4*k+1){
        ll mid=(l+r)/2;
        if(check(l,mid)){
            r=mid;
            if(l==mid) return 0;
        }
        else l=min(mid+1,r);
        l=max((ll)1,l-k);r=min(n,r+k);
    }
    int num=0;
    while(1){
        num=(rand()+rand())%(r-l+1);
        if(check(l+num,l+num))return 0;
        l=max((ll)1,l-k);r=min(n,r+k);
        ll mid=(l+r)/2;
        if(check(l,mid)){
            r=mid;
            if(l==mid) return 0;
        }
        else l=min(mid+1,r);
        l=max((ll)1,l-k);r=min(n,r+k);
        num++;
    }
    return 0;
}