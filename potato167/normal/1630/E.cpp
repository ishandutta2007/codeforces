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
#define rep(i,a) for (int i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}


namespace po167{
struct combination{
	std::vector<long long> rev;
	long long MOD;
	combination(int max,long long mod):MOD(mod),rev(max+1){
		for(long long i=0;i<=max;i++){
			if(i<2){
				rev[i]=1;
				continue;
			}
			rev[i]=mod-((mod/i)*rev[mod%i])%mod;
		}
	}
};
}
using po167::combination;

combination rev_table(1e6+10,mod);

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

//
long long Gcd(long long a,long long b){
	if(b==0) return a;
	else return Gcd(b,a%b);
}


//N
vector<long long> Divisors(long long N){
    vector<long long> p,q;
    long long i=1,K=0;
    while(i*i<N){
        if(N%i==0){
            p.push_back(i);
            q.push_back(N/i);
            K++;
        }
        i++;
    }
    if(i*i==N) p.push_back(i);
    for(int i=K-1;i>=0;i--){
        p.push_back(q[i]);
    }
    return p;
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
	ll n;
	cin>>n;
	map<int,ll> m;
	rep(i,n){
		int a;
		cin>>a;
		m[a]++;
	}
	ll A=-1;
	vector<int> p;
	for(auto x:m) p.push_back(x.second);
	A=p[0];
	int l=p.size();
	if(l==1){
		cout<<"1\n";
		return ;
	}
	rep(i,l-1) A=Gcd(A,p[i+1]);
	auto table=Divisors(A);
	vector<pair<ll,ll>> val(A+1);
	ll fact=1;
	for(auto y:p){
		for(ll i=1;i<=y;i++) y=(y*i)%mod;
	}
	for(auto roop:table){
		ll tmp=fact;
		ll z=roop;
		for(auto y:p){
			for(ll i=roop;i<=y;i+=roop){
				tmp*=z;
				z+=roop;
				tmp%=mod;
				tmp*=rev_table.rev[i];
				tmp%=mod;
			}
		}
		val[roop].first=tmp;
		ll len=n/roop;
		ll x=0;
		for(auto y:p){
			ll z=y/roop;
			x+=(z*(z-1));
			x%=mod;
		}
		x*=(ll)(roop);
		x%=mod;
		x*=rev_table.rev[len-1];
		x%=mod;
		val[roop].second=(x*tmp)%mod;
		//cout<<roop<<" "<<tmp<<" "<<x<<"\n";
	}
	ll base=0,ans=0;
	rep(i,n){
		int r=n/Gcd(i,n);
		if(A%r==0){
			//cout<<A<<" "<<i<<"\n";
			base+=val[r].first;
			ans+=val[r].second;
			base%=mod,ans%=mod;
		}
	}
	cout<<(n-(jyo(base,mod-2,mod)*ans)%mod+mod)%mod<<"\n";
}