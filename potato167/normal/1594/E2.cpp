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
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

vector<ll> f(vector<ll> a,vector<ll> b){
	vector<ll> c(3);
	rep(i,3) rep(j,3) rep(k,3){
		if(i!=k&&j!=k){
			c[k]=(c[k]+(a[i]*b[j])%mod)%mod;
		}
	}
	return c;
}

void out(vector<ll> p){
	rep(i,3) cout<<p[i]<<" ";
	cout<<"\n";
}

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



void solve();
//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	ll k,n;
	cin>>k>>n;
	vector<ll> p(n);
	vector<map<ll,vector<ll>>> m(k);
	vector<vector<pair<ll,int>>> c(k); 
	rep(i,n){
		cin>>p[i];
		ll l=2;
		ll x=0;
		while(p[i]>l-1) l*=2ll,x++;
		int ind=0;
		string S;
		cin>>S;
		if(S[0]=='o'||S[0]=='r') ind=1;
		if(S[0]=='b'||S[0]=='g') ind=2;
		c[x].push_back({p[i],ind});
	}
	vector<ll> tmp={1,1,1};
	for(int deep=k-1;deep>=0;deep--){
		for(auto x:c[deep]){
			if(!m[deep].count(x.first)) m[deep][x.first]=tmp;
			rep(i,3){
				if(i!=x.second) m[deep][x.first][i]=0;
			}
		}
		if(deep==0) break;
		for(auto x:m[deep]){
			//cout<<x.first<<" ";
			//out(x.second);
			if(x.first%2==1&&m[deep].count(x.first-1)) continue;
			if(x.first%2==0&&m[deep].count(x.first+1)){
				m[deep-1][x.first/2]=f(x.second,m[deep][x.first+1]);
			}else m[deep-1][x.first/2]=f(tmp,x.second);
		}
		tmp=f(tmp,tmp);
		//out(tmp);
	}
	ll ans=jyo(2,jyo(2,k,mod-1)-n+mod-2,mod);
	//cout<<ans<<"\n";
	if(n==0){
		cout<<(((ans*tmp[0])%mod)*3ll+mod*3ll)%mod;
	}else{
		ll z=0;
		rep(i,3) z+=m[0][1][i];
		z%=mod;
		cout<<((ans*z)%mod+mod)%mod<<"\n";
	}
}