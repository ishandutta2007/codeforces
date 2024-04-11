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
const int INF=2100000000;
ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

ll f(ll a){
    return (a*(a-1))/2;
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> x(n),y(m);
    rep(i,n) cin>>x[i];
    rep(i,m) cin>>y[i];
    vector<map<int,ll>> line(n+m);
    int L=1e6;
    ll ans=0;
    rep(i,k){
        int c,d;
        cin>>c>>d;
        int a=LB(x,c);
        int b=LB(y,d);
        if(x[a]==c&&y[b]==d) continue;
        else if(x[a]==c){
            line[n+b][a]++;
        }
        else line[a][b]++;
    }
    for(auto tmp:line){
        ll sum=0;
        for(auto z:tmp){
            sum+=z.second;
            ans-=f(z.second);
        }
        ans+=f(sum);
    }
    cout<<ans<<"\n";
}



//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t) solve();
}