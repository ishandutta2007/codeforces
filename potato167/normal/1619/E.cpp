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
const ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

ll f(ll n,int a){
    ll l=0,r=10+pow(n,(ld)(1)/(ld)(a));
    while(r-l>1){
        ll med=(r+l)/2;
        ll val=1;
        rep(i,a) val*=med;
        if(n<val) r=med;
        else l=med;
    }
    return l;
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
	int n;
    cin>>n;
    vector<ll> p(n+1);
    priority_queue<ll> pq;
    rep(i,n){
        int a;
        cin>>a;
        p[a]++;
    }
    ll tmp=0;
    rep(i,n){
        if(i) cout<<" ";
        ll ans=tmp;
        /*for(int j=i;j<n;j++){
            if(p[j]==i) ans++;
            else break;
        }*/
        //ans+=UB(p,i)-LB(p,i);
        cout<<ans+p[i];
        rep(j,p[i]) pq.push(i);
        if(pq.empty()){
            rep(j,n-i){
                cout<<" -1";
            }
            cout<<"\n";
            return ;
        }
        tmp+=i-pq.top();
        pq.pop();
    }
    cout<<" "<<tmp<<"\n";
}