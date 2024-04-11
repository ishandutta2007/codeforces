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
const ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

ll jyo(ll x,ll y,ll z){
  ll H=y; //
       ll a=1,b=x,c=1;
       while(H>0){
         a*=2;
         if(H%a!=0){
           H-=a/2;
           c*=b;
           c%=z;
         }
        b*=b;
         b%=z;
      } //
 return c;
}



int f(int a,int n){
    a%=(2*n-2);
    if(a==0) a=n*2-2;
    if(a>n){
        return 2*n-a;
    }
    return a;
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
    ll n,m,a,b,c,d,pro;
    cin>>n>>m>>a>>b>>c>>d>>pro;
    pro*=jyo(100,mod-2,mod);
    pro%=mod;
    set<ll> s;
    rep(i,n*2-2){
        if(c==f(a+i,n)){
            rep(j,(m-1)){
                s.insert(i+(n*2-2)*j);
            }
        }
    }
    rep(i,m*2-2){
        if(d==f(b+i,m)){
            rep(j,(n-1)){
                s.insert(i+(m*2-2)*j);
            }
        }
    }
    ll ans=0;
    ll tmp=1;
    for(auto x:s){
        //cout<<x<<" ";
        ans+=((((x%mod)*pro)%mod)*tmp)%mod;
        tmp*=(1-pro);
        tmp%=mod;
        ans%=mod;
    }
    //cout<<((ans*16)%mod+mod)%mod<<"\n";
    ans*=(jyo(1-tmp,mod-2,mod));
    ans%=mod;
    tmp*=(jyo(1-tmp,mod-2,mod));
    tmp%=mod;
    tmp*=((n-1)*(m-1)*2)%mod;
    ans+=tmp;
    cout<<(ans%mod+mod)%mod<<"\n";
}