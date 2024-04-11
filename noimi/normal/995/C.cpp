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


    
void go();

main(){
    ios
    int tc=1;
    // tc=in();
    while(tc--){
        go();
    }
    return 0;
}

struct line{
    int id,x,y;
};

vec pre;

vector<vec> g;
    vec x,y,d;

void dfs(int x,int t){
    d[x]*=t;
    t*=-1;
    for(auto e:g[x])dfs(e,t);
}
void go(){
    int n=in();
    g.resize(n);
    d.resize(n);
    rep(i,n)d[i]=1;
    rep(i,n)x.pb(in()),y.pb(in());
    rep(i,n)if(x[i]<0){
        x[i]*=-1,y[i]*=-1;
        d[i]=-1;
    }
    long double pi=atan2(0,-1);
    pre=vec(n,-1);
    vec mem(n,0);
    vector<line> a,b,c;
    rep(i,n){
        long double t=atan2(x[i],y[i]);
        if(t<pi/3)a.pb(line{(int)i,x[i],y[i]});
        else if(t<pi*2/3)b.pb(line{(int)i,x[i],y[i]});
        else c.pb(line{(int)i,x[i],y[i]});
    }
    while(a.size()>1 or b.size()>1 or c.size()>1){
        if(a.size()>1){
            line t=a.back();a.pop_back();
            line s=a.back();a.pop_back();
            line next;
            if(t.x<s.x){
                next=line{s.id,s.x-t.x,s.y-t.y};
                g[s.id].pb(t.id);
            }
            else{
                next=line{t.id,t.x-s.x,t.y-s.y};
                g[t.id].pb(s.id);
            }
            long double T=atan2(next.x,next.y);
            if(T<pi/3)a.pb(next);
            else if(T<pi*2/3)b.pb(next);
            else c.pb(next);
        }
        else if(b.size()>1){
            line t=b.back();b.pop_back();
            line s=b.back();b.pop_back();
            line next;
            if(t.x<s.x){
                next=line{s.id,s.x-t.x,s.y-t.y};
                g[s.id].pb(t.id);
            }
            else{
                next=line{t.id,t.x-s.x,t.y-s.y};
                g[t.id].pb(s.id);
            }
            long double T=atan2(next.x,next.y);
            if(T<pi/3)a.pb(next);
            else if(T<pi*2/3)b.pb(next);
            else c.pb(next);
        }
        else{
            line t=c.back();c.pop_back();
            line s=c.back();c.pop_back();
            line next;
            if(t.x<s.x){
                next=line{s.id,s.x-t.x,s.y-t.y};
                g[s.id].pb(t.id);
            }
            else{
                next=line{t.id,t.x-s.x,t.y-s.y};
                g[t.id].pb(s.id);
            }
            long double T=atan2(next.x,next.y);
            if(T<pi/3)a.pb(next);
            else if(T<pi*2/3)b.pb(next);
            else c.pb(next);
        }
    }
    int m=a.size()+b.size()+c.size();
    vector<line> v;
    if(a.size())v.pb(a[0]);
    if(b.size())v.pb(b[0]);
    if(c.size())v.pb(c[0]);
    int t[3];
    rep(i,1<<m){
        rep(j,m){
            if(i&(1<<j))t[j]=1;
            else t[j]=-1;
        }
        ll a=0,b=0;
        rep(j,m)a+=t[j]*v[j].x,b+=t[j]*v[j].y;
        if((ll)a*a+(ll)b*b<=2250000000000ll){
            break;
        }
    }
    rep(i,m){
        dfs(v[i].id,t[i]);
    }
    print(d);

}