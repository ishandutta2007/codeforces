// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vec>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define endl "\n"
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))
#define MM " "
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}

long double eps=1e-8;
unsigned xorshift()
{
    static unsigned x=123456789, y=362436069, z=521288629, w=8867512;
    unsigned t=(x^(x<<11));
    x=y; y=z; z=w;
    return w=(w^(w>>19))^(t^(t>>8));
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n){
    return xorshift()%(n);
}
double drnd(){
    return (double)(rnd(INT_MAX))/INT_MAX;
}
void shuffle(vec &x){
    int n=x.size();
    rep3(i,n-1,1){
        swap(x[i],x[rnd(i-1)]);
    }
}
clock_t start;
double time(){
    return (double)(clock()-start)/CLOCKS_PER_SEC;
}

int l2(int x){
    int res=-1;
    while(x){
        res++;
        x>>=1;
    }
    return res;
}
main(){
    int T=in();
    while(T--){
        string s;cin>>s;
        string t;cin>>t;
        int n=s.size(),m=t.size();
        bool fl=false;
        rep2(i,0,m-1){
            string t1=t.substr(0,i),t2=t.substr(i,m-i);
            int dp[n+10];
            rep(j,n+1)dp[j]=-1;
            dp[0]=0;
            rep(j,n){
                rep3(k,i,0){
                    if(dp[k]==-1)continue;
                    if(t1[k]==s[j])chmax(dp[k+1],dp[k]);
                    if(dp[k]!=m-i and t2[dp[k]]==s[j]){
                        dp[k]++;
                    }
                }
            }
            if(dp[i]==m-i){
                cout<<"YES\n";goto end;
            }
        }
        cout<<"NO\n";
        end:;
    }
}