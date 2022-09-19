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
const ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}



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
    int n;
	cin>>n;
	int M=26;
	vector<vector<int>> p(n,vector<int>(M));
	rep(i,n){
		string S;
		cin>>S;
		S+='%';
		int ind=0;
		rep(j,M){
			while(S[ind]==(char)('a'+j)) p[i][j]++,ind++;
		}
	}
	int L=(1<<n);
	vector<ll> dp(L,1);
	vector<int> order(n);
	rep(i,n) order[i]=i;
	rep(ch,M){
		int tmp=0;
		sort(order.begin(),order.end(),[&](int l,int r){
			return p[l][ch]>p[r][ch];
		});
		//cout<<ch<<endl;
		rep(j,n){
			//cout<<j<<" "<<order[j]<<endl;
			for(int i=L-1;i>=0;i--){
				i&=tmp;
				//cout<<i<<endl;
				dp[i+(1<<order[j])]*=(1+p[order[j]][ch]);
			}
			tmp+=(1<<order[j]);
		}
		rep(i,L) dp[i]%=mod;
	}
	dp[0]=0;
	rep(i,L){
		int sign=-1;
		rep(j,n){
			if(i&(1<<j)) sign*=-1;
		}
		dp[i]*=sign;
	}
	rep(i,n){
		rep(j,L){
			if(j&(1<<i)){
				dp[j]+=dp[j^(1<<i)];
				dp[j]%=mod;
			}
		}
	}
	ll ans=0;
	rep(i,L){
		ll base=0;
		ll c=0;
		rep(j,n){
			if(i&(1<<j)){
				base+=j+1;
				c++;
			}
		}
		base*=c;
		//cout<<c<<" "<<base<<" "<<dp[i]<<endl;
		ans^=(((dp[i]%mod+mod)%mod)*base);
	}
	cout<<ans<<"\n";
}