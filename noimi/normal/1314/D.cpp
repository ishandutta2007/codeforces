#pragma GCC optimize("O3")
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
#define vec2ll(a,b) vector<vecll>(a,vecll(b))
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



constexpr int INF=1e9+10;
constexpr int S=81;
#define int unsigned int
int d[5][5],tmp[5][5],nxt[5][5];
int black[6],white[80];
int ans=INT_MAX;
pii mem[S][S][S];
main(){
    ios
    int n=in(),k=in();
    int kk=k/2;
    bool col[S]={};
    // rep(i,kk-1)col[i]=1;
    // sort(col,col+n);
    rep2(i,n-kk+1,n-1)col[i]=1;
    int Mat[S][S];
    rep(i,n)rep(j,n){
        Mat[i][j]=in();
        if(i==j)Mat[i][j]=INF;
    }
    rep(i,n){
        rep(j,n){
            rep(s,n){
                mem[i][j][s]={Mat[i][s]+Mat[s][j],s};
            }
            sort(mem[i][j],mem[i][j]+n);
        }
    }
    int ans=INT_MAX;
    do{
        if(col[0]==1)col[0]=0;
        int b=1,w=0;
        rep2(i,1,n-1){
            if(col[i])black[b++]=i;
            else white[w++]=i;
        }
        const int T=b;
        rep(i,T)rep(j,T)d[i][j]=INF;
        rep(i,T)rep(j,T){
            rep(ii,n){
                if(col[mem[black[i]][black[j]][ii].second]==0){
                    d[i][j]=mem[black[i]][black[j]][ii].first;
                    break;
                }
            }
        }
        rep(i,T)rep(j,T)tmp[i][j]=d[i][j];
        rep(i,kk-1){
            rep(i,T)rep(j,T){
                int t=INF;
                rep(s,T){
                    chmin(t,tmp[i][s]+d[s][j]);
                }
                nxt[i][j]=t;
            }
            rep(i,T)rep(j,T)tmp[i][j]=nxt[i][j];
        }
        chmin(ans,tmp[0][0]);

    }while(next_permutation(col,col+n));
    cout<<ans<<endl;
}