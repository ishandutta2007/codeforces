#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=1167167167167167167;
const int INF=1000000000;
const ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

ll f(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c){
    b.first-=a.first;
    b.second-=a.second;
    c.first-=a.first;
    c.second-=a.second;
    return abs(b.first*c.second-b.second*c.first);
}

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
    ll h,w;
    cin>>h>>w;
    vector<vector<ll>> p(4);
    vector<int> q(4);
    rep(i,4){
        cin>>q[i];
        rep(j,q[i]){
            int a;
            cin>>a;
            p[i].push_back(a);
        }
    }
    ll ans=0;
    /*rep(i,q[0]){
        chmax(ans,f({p[0][i],0},{0,p[2][q[2]-1]},{h,p[3][q[3]-1]}));
    }
    rep(i,q[1]){
        chmax(ans,f({p[1][i],w},{0,p[2][0]},{h,p[3][0]}));
    }
    rep(i,q[2]){
        chmax(ans,f({0,p[2][i]},{p[0][q[0]-1],0},{p[1][q[1]-1],w}));
    }
    rep(i,q[3]){
        chmax(ans,f({h,p[3][i]},{p[0][0],0},{p[1][0],w}));
    }*/
    chmax(ans,w*(p[0][q[0]-1]-p[0][0]));
    chmax(ans,w*(p[1][q[1]-1]-p[1][0]));
    chmax(ans,h*(p[2][q[2]-1]-p[2][0]));
    chmax(ans,h*(p[3][q[3]-1]-p[3][0]));
    cout<<ans<<"\n";
}