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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n){
    return uniform_int_distribution<int>(0, n)(rng);
}
double drnd(){
    return (double)(rnd(INT_MAX))/INT_MAX;
}
const int N=310000;
int col[N];
struct UnionFind {
  vector< int > data;
 
  UnionFind(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
};

int par[310000];
main(){
    ios
    int n=in(),k=in();
    string s;cin>>s;
    vector<pii> id(n+1);
    rep(i,k){
        int m=in();
        rep(j,m){
            int t=in();
            if(id[t].first==0)id[t].first=i+1;
            else {
                id[t].second=i+1;
                if(id[t].second<id[t].first)swap(id[t].first,id[t].second);
            }
        }
    }
    map<pii,int> mp;
    rep2(i,1,n){
        if(id[i]==pii{0,0}){par[i]=-1;continue;}
        if(mp[id[i]]==0){
            mp[id[i]]=i;
            par[i]=i;
        }
        else{
            par[i]=mp[id[i]];
        }
    }
    int pre=0;
    vector<vec> v(k+1);
    rep2(i,1,k)v[i].pb(i);
    int par2[N];
    vec sz(k+1,1),bl(k+1);
    vec cnt(k+1);
    vec kakutei(k+1);
    rep2(i,1,k)par2[i]=i;
    rep2(i,1,n){
        int c=(s[i-1]=='0');
        int p=par[i];
        if(p==-1){cout<<pre<<endl;continue;}
        // print(bl);print(sz);
        if(p<i)cout<<pre<<endl;
        else{
            if(id[i].second==0){
                int pp=par2[id[i].first];
                kakutei[pp]=1;
                int tmp=col[id[i].fi]^cnt[pp];
                if(tmp==c)cout<<pre<<endl;
                else{
                    pre-=bl[pp]*2-sz[pp];
                    bl[pp]=sz[pp]-bl[pp];
                    cnt[pp]^=1;
                    cout<<pre<<endl;
                }
            }
            else{
                int p1=par2[id[i].fi],p2=par2[id[i].se];
                if(p1==p2){
                    cout<<pre<<endl;
                    continue;
                }
                int lcol=col[id[i].fi]^cnt[p1];
                int rcol=col[id[i].se]^cnt[p2];
                if( (lcol ^ rcol)!= c){
                    if(kakutei[p1]){
                        pre-=bl[p2]*2-sz[p2];
                        bl[p2]=sz[p2]-bl[p2];
                        cnt[p2]^=1;
                    }
                    else if(kakutei[p2]){
                        pre-=bl[p1]*2-sz[p1];
                        bl[p1]=sz[p1]-bl[p1];
                        cnt[p1]^=1;
                    }
                    else{
                        if(bl[p1]*2-sz[p1]>bl[p2]*2-sz[p2]){
                            pre-=bl[p1]*2-sz[p1];
                            bl[p1]=sz[p1]-bl[p1];
                            cnt[p1]^=1;
                        }
                        else{
                            pre-=bl[p2]*2-sz[p2];
                            bl[p2]=sz[p2]-bl[p2];
                            cnt[p2]^=1;
                        }
                    }
                }
                cout<<pre<<endl;
                if(sz[p1]>sz[p2])swap(p1,p2);
                for(auto e:v[p1])v[p2].pb(e);
                for(auto e:v[p1])par2[e]=p2;
                for(auto e:v[p1])col[e]^=(cnt[p1]^cnt[p2]);
                sz[p2]+=sz[p1];
                bl[p2]+=bl[p1];
                kakutei[p2]=(kakutei[p1]|kakutei[p2]);
            }
        }
    }
                    

}