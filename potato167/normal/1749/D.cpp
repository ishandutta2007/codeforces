#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
const int INF=2100000000;
const ll mod=998244353;
#define rep(i,a) for (int i=0;i<a;i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}
template<class T> T min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}

ll jyo(ll x,ll y,ll z){
  ll H=y; //
       ll a=1,b=(x%z+z)%z,c=1;
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


//a:Nlog(log(N))
vector<long long> Eratosthenes(long long a){
    if(a<2) return {};
    vector<long long> p(a+1),ans;
    p[0]=1,p[1]=1;
    long long k=2;
    while(k*k<=a){
        if(p[k]==0){
            ans.push_back(k);
            for(long long i=2;i*k<=a;i++){
                p[i*k]=1;
            }
        }
        k++;
    }
    while(k<=a){
        if(p[k]==0) ans.push_back(k);
        k++;
    }
    return p;
}

void solve();
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	//cin>>t;
	rep(i,t) solve();
}
void solve(){
	ll n,m;
	cin>>n>>m;
	ll ans=0;
	ll tmp=m%mod;
	ll x=m%mod;
	ll val=1;
	auto E=Eratosthenes(n+100);
	for(ll i=2;i<=n;i++){
		if(E[i]==0) val=(val*i);
		if(val>m){
			val=m+1;
		}
		tmp=(tmp*((m/val)%mod))%mod;
		x=(x*(m%mod))%mod;
		ans=(ans+x)%mod;
		ans=(ans-tmp)%mod;
		//cout<<x<<" "<<tmp<<"\n";
	}
	cout<<(ans+mod)%mod<<"\n";
}