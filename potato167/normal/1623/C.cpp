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
    vector<ll> p(n);
    rep(i,n) cin>>p[i];
    int L=0,R=INF;
    while(R-L>1){
        int med=(R+L)/2;
        vector<ll> q(n);
        int J=1;
        for(int i=n-1;i>1;i--){
            if(p[i]+q[i]<med){
                J=0;
                break;
            }
            ll d=(p[i]-max(0ll,med-q[i]))/3;
            q[i-2]+=d*2;
            q[i-1]+=d;
        }
        if(J==1&&min(p[0]+q[0],p[1]+q[1])>=med) L=med;
        else R=med;
    }
    cout<<L<<"\n";
}