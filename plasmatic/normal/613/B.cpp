#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);
 
#define MAXN 100005
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unordered_map<int,int> umii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;
 
mt19937 g1(time(0));
 
int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}
 
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
 
int len,A,perf,minc,ans[MAXN];
pii arr[MAXN];
ll budget,psa[MAXN];
pair<ll,int> res;
 
inline ll gsum(int i, ll s){
    int low = i+1, high = len, ans = len;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid].first <= s){
            ans = mid;
            high = mid-1;
        }else low = mid+1;
    }
    ll cost = 1LL*(len-ans+1)*s-(psa[len]-psa[ans-1]);
    return cost;
}
 
inline pair<ll,int> fnd(int i, ll rem){
    int low = arr[len].first, high = A, ans = low;
    while(low <= high){
        ll mid = (low+high)/2;
        ll c2 = gsum(i,mid);
        if(c2 <= rem){
            ans = mid;
            low = mid+1;
        }else high = mid-1;
    }
    ll temp = 1LL*i*perf+1LL*ans*minc;
    if(ans == A) temp = 1LL*len*perf+1LL*A*minc;
    return mp(temp,ans);
}
 
int main(){
    scanf("%d %d %d %d %lld",&len,&A,&perf,&minc,&budget);
    for(int i=1; i<=len; i++){
        scanf(" %d",&arr[i].first);
        arr[i].second = i;
        ans[i] = arr[i].first;
    }
    sort(arr+1,arr+len+1,greater<pii>());
    for(int i=1; i<=len; i++)
        psa[i] = psa[i-1]+arr[i].first;
    for(int i=0; i<=len; i++){
        ll cost = 1LL*A*i-psa[i];
        if(cost > budget) break;
        pll tmp = fnd(i,budget-cost);
        res = max(res,mp(tmp.first,i));
    }
    printf("%lld\n",res.first);
    for(int i=1; i<=res.second; i++)
        ans[arr[i].second] = A;
    pair<ll,int> tmp = fnd(res.second,budget-1LL*A*res.second+psa[res.second]);
    for(int i=res.second+1; i<=len; i++)
        if(arr[i].first < tmp.second)
            ans[arr[i].second] = tmp.second;
    for(int i=1; i<=len; i++)
        printf("%d ",ans[i]);
}