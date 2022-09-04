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
#define INF 100000000
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
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    int tc=1;
    // tc=in();
    while(tc--){
        go();
    }
    return 0;
}



void go(){
    int n=in();
    vec a;
    rep(i,n)a.pb(in());
    if(n<7){
        vec ans;
        rep(i,n-2){
            if(a[i]){
                rep(j,3)a[i+j]^=1;
                ans.pb(i+1);
            }
        }
        if(a[n-1] or a[n-2]){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            cout<<ans.size()<<endl;
            rep(i,ans.size()){
                cout<<ans[i]<<" "<<ans[i]+1<<" "<<ans[i]+2<<endl;
            }
        }
    }
    else if(n==7){
        vec ans;
        rep(i,n-2){
            if(a[i]){
                rep(j,3)a[i+j]^=1;
                ans.pb(i+1);
            }
        }
        if(a[n-2]){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            cout<<ans.size()+(a[n-1]? 3:0)<<endl;
            rep(i,ans.size()){
                cout<<ans[i]<<" "<<ans[i]+1<<" "<<ans[i]+2<<endl;
            }
            cout<<"1 2 3\n2 3 4\n1 4 7\n";
        }
    }
    else{
        int pos=0;
        vector<vec> ans;
        while(1){
            while(pos<n and a[pos]==0)pos++;
            if(pos==n)break;
            if(pos+2>n-1){
                if(a[pos+1])ans.pb({pos-4,pos-1,pos+2}),ans.pb({pos-4,pos-3,pos-2}),ans.pb({pos-3,pos-2,pos-1});
                if(a[pos])ans.pb({pos-5,pos-2,pos+1}),ans.pb({pos-5,pos-4,pos-3}),ans.pb({pos-4,pos-3,pos-2});
                break;
            }
            else{
                if(a[pos] and a[pos+1] and a[pos+2]){
                    a[pos]=a[pos+1]=a[pos+2]=0;
                    ans.pb({pos+1,pos+2,pos+3});
                }
                else if(a[pos] and a[pos+2]){
                    if(pos+4>n-1){
                        a[pos]=a[pos+1]=a[pos+2]=0;
                        a[pos+1]=1;
                        ans.pb({pos+1,pos+2,pos+3});
                    }
                    else a[pos]=a[pos+2]=0,a[pos+4]^=1,ans.pb({pos+1,pos+3,pos+5});
                }
                else{
                    int next=pos+2;
                    while(next<n and !a[next]){
                        next++;
                    }
                    if(next*2-pos>n-1){
                        if(pos-5<=0){
                            a[pos]^=1;
                            a[pos+1]^=1;
                            a[pos+2]^=1;
                            ans.pb({pos+1,pos+2,pos+3});
                        }
                        else{
                        ans.pb({pos-5,pos-2,pos+1}),ans.pb({pos-5,pos-4,pos-3}),ans.pb({pos-4,pos-3,pos-2});
                        a[pos]=0;
                        }
                    }
                    else{
                        ans.pb({pos+1,next+1,next*2-pos+1});
                        a[pos]^=1;
                        a[next]^=1;
                        a[next*2-pos]^=1;
                    }
                }
            }
        }
        cout<<"YES\n";
        cout<<ans.size()<<endl;
        for(auto e:ans){
            print(e);
        }
    }

}