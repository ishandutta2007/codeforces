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

int mp[4][51];
struct mov{
    int i,r,c;
};
int nx[4]={1,0,3,2};
void go(){
    int n=in(),k=in();
    rep(i,4)rep(j,n)cin>>mp[i][j];
    vector<mov> ans;
    vecpii v;
    rep(i,n)v.eb(1,i);
    rep3(i,n-1,0)v.eb(2,i);
    vecpii vv=v;
    for(auto e:vv)v.pb(e);
    if(1){
        bool f=0;
        rep(i,n)f|=(mp[0][i]==mp[1][i] or mp[2][i]==mp[3][i] or mp[1][i]==0 or mp[2][i]==0);
        if(!f){
            cout<<-1<<endl;return;
        }
        pii mem;
        int c;
        rep(i,2){
            rep(j,n)if(mp[i*2][j]==mp[i*2+1][j]){
                mem={(i?2:1),j},c=mp[i*2][j];
                break;
            }
        }   
        rep(i,n){
            if(mp[1][i]==0)mem={1,i};
            if(mp[2][i]==0)mem={2,i};
        }
        if(mp[mem.fi][mem.se]){
            ans.pb(mov{c,nx[mem.fi],mem.se});
            mp[mem.fi][mem.se]=0;
        }
        vecpii t;
        int now=0;
        while(v[now]!=mem)now++;
        now++;
        while(1){
            t.pb(v[now++]);
            if(v[now-1]==mem){break;}
        }
        int res=k-ans.size();
        pii pre=mem;
        while(res){
            for(auto p:t){
                if(mp[p.fi][p.se] and mp[p.fi][p.se]==mp[nx[p.fi]][p.se]){
                    ans.pb(mov{mp[p.fi][p.se],nx[p.fi],p.se});
                    mp[p.fi][p.se]=0;
                    res--;
                }
                else if (mp[p.fi][p.se]){
                    ans.pb(mov{mp[p.fi][p.se],pre.fi,pre.se});
                    mp[pre.fi][pre.se]=mp[p.fi][p.se];
                    mp[p.fi][p.se]=0;
                }
                pre=p;
            }
        }
        cout<<ans.size()<<endl;
        for(auto e:ans){
            cout<<e.i<<" "<<e.r+1<<" "<<e.c+1<<endl;
        }
    }
}