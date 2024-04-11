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
const ll MOD=1e9+7;
const int N=2100000;


int n,m,k;
bool is_in(int x,int y){
    return (x>=0 and x<n and y>=0 and y<m);
}
int g[50][50];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

struct lego{
    int x,y, sz;
};
const int T=10;
int r[T+5][510][510];
main(){ios
    int n=in(),m=in(),q=in();
    vector<string> v;
    rep(i,n){
        string s;cin>>s;
        v.pb(s);
    }
    if(n==1 or m==1){
        rep(i,q){
            in(),in(),in(),in();
            cout<<0<<endl;
        }
        return 0;
    }
    vector<lego> big;
    rep(i,n-1){
        rep(j,m-1){
            if(v[i][j]=='R' and v[i][j+1]=='G' and v[i+1][j]=='Y' and v[i+1][j+1]=='B'){
                int d=min(i+1,n-1-i);
                d=min(d,min((int)j+1,m-1-(int)j));
                int tmp=1;
                rep2(k,2,d){
                    bool flag=true;
                    int ii=i+1-k,jj=j+1-k;
                    rep(kk,k)if(v[ii][jj+kk]!='R' || v[ii+kk][jj]!='R')flag=false;
                    jj+=2*k-1;
                    rep(kk,k)if(v[ii][jj-kk]!='G' || v[ii+kk][jj]!='G')flag=false;
                    ii+=2*k-1;
                    rep(kk,k)if(v[ii][jj-kk]!='B' or v[ii-kk][jj]!='B')flag=false;
                    jj-=2*k-1;
                    rep(kk,k)if(v[ii][jj+kk]!='Y' or v[ii-kk][jj]!='Y')flag=false;
                    if(flag)tmp=k;
                    else break;
                }
                if(tmp>=T){
                    big.pb(lego{(int)i,(int)j,tmp});
                }
                else{
                    rep2(iii,1,tmp)r[iii][i][j]+=1;
                }
            }
        }
    }
    rep(i,n+5){
        rep(j,m+5){
            rep2(k,1,T){
                r[k][i+1][j]+=r[k][i][j];
            }
        }
    }
    rep(i,n+5)rep(j,m+5)rep2(k,1,T)r[k][i][j+1]+=r[k][i][j];
    while(q--){
        int a=in()-1,b=in()-1,c=in()-1,d=in()-1;
        int ans=0;
        for(auto now:big){
            int x=now.x,y=now.y,sz=now.sz;
            sz=min(sz,x-a+1);
            sz=min(sz,y-b+1);
            sz=min(sz,c-x);
            sz=min(sz,d-y);
            if(sz>0)
            ans=max(ans,sz);
        }
        if(ans>=T)cout<<ans*ans*4<<endl;
        else{
            a--,b--;
            rep2(i,1,T){
                c--;d--;
                if(c<0 or d<0)break;
                if(a >= c or b>=d ) break;
                int sum=r[i][c][d];
                if(b>=0)sum-=r[i][c][b];
                if(a>=0)sum-=r[i][a][d];
                if(b>=0 and a>=0)sum+=r[i][a][b];
                if(sum>0)ans=max(ans,(int)i);
                else break;
                // cout<<sum<<endl;
                a++,b++;
            }
            cout<<ans*ans*4<<endl;
        }
    }

            
}