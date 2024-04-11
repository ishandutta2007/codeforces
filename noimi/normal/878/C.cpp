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
// #define INF 100000000
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
string stin() {string s;cin>>s;return s;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}

struct T{
    array<int,10> mi,ma;
    int cnt;
    bool operator<(const T &rhs) const {
        rep(i,10)if(mi[i]<rhs.ma[i])return false;
        return true;
    }
};
bool cmp(T x,T y){
    rep(i,10){
        if(x.mi[i]<y.ma[i])return false;
    }
    return true;
}
void merge(T &x,T y){
    rep(i,10)chmin(x.mi[i],y.mi[i]);
    rep(i,10)chmax(x.ma[i],y.ma[i]);
    x.cnt+=y.cnt;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    int n=in(),k=in();
    set<T> se;
    rep(i,n){
        array<int,10> tmp;
        rep(j,k)cin>>tmp[j];
        T now ={tmp,tmp,1};
        if(se.empty()){
            se.insert(now);
        }
        else{
            auto it = se.lower_bound(now);
            while(it!=se.end()){
                if(now < (*it)){
                    break;
                }
                else {
                    merge(now,*it);
                    it = se.erase(it);
                }
            }
            se.insert(now);
        }
        cout<<(*se.begin()).cnt<<endl;
    }


}