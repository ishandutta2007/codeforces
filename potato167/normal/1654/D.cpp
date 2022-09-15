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
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}

int L=2e5+10;
vector<vector<pair<int,int>>> table(L);
vector<int> exist;
vector<int> count(L);
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



void solve();
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	rep(i,L){
		if(i<2) continue;
		if(table[i].size()==0){
			for(int j=i;j<L;j+=i){
				int D=j;
				int c=0;
				while(D%i==0) c++,D/=i;
				table[j].push_back({i,c});
			}
		}
	}
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int N;
	cin>>N;
	vector<vector<tuple<int,int,int>>> G(N);
	rep(i,N-1){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--,b--;
		int e=__gcd(c,d);
		c/=e,d/=e;
		G[a].push_back({b,c,d});
		G[b].push_back({a,d,c});
	}
	vector<ll> order={0},pare(N,-1);
	pare[0]=-2;
	rep(i,N){
		int a=order[i];
		for(auto x:G[a]){
			int ind=get<0>(x);
			if(pare[ind]==-1){
				pare[ind]=a;
				order.push_back(ind);
			}
		}
	}
	vector<map<int,int>> mother(N);
	vector<ll> dp_sum(N),dp_un(N);
	for(int i=N-1;i>=0;i--){
		int a=order[i];
		int sw=-1;
		//cout<<"Start "<<a<<"\n";
		for(auto x:G[a]){
			int ind=get<0>(x);
			if(pare[ind]!=a) continue;
			int c=get<1>(x);
			int d=get<2>(x);
			ll diff=c;
			diff=(diff*dp_un[ind])%mod;
			for(auto y:table[c]){
				mother[ind][y.first]+=y.second;
			}
			for(auto y:table[d]){
				if(mother[ind][y.first]<=y.second){
					diff=(diff*jyo(y.first,mod-1-mother[ind][y.first],mod))%mod;
					mother[ind].erase(y.first);
				}
				else{
					mother[ind][y.first]-=y.second;
					diff=(diff*jyo(y.first,mod-1-y.second,mod))%mod;
				}
			}
			if(sw==-1||mother[ind].size()>mother[sw].size()){
				sw=ind;
				dp_un[a]=diff;
			}
			//cout<<ind<<" "<<diff<<"\n";
		}
		if(sw==-1){
			dp_sum[a]=1;
			dp_un[a]=1;
			continue;
		}
		//cout<<"diff "<<dp_un[a]<<" ";
		swap(mother[a],mother[sw]);
		for(auto x:G[a]){
			int ind=get<0>(x);
			if(pare[ind]!=a||ind==sw) continue;
			for(auto y:mother[ind]){
				if(mother[a][y.first]<y.second){
					dp_un[a]=(dp_un[a]*jyo(y.first,y.second-mother[a][y.first],mod))%mod;
					mother[a][y.first]=y.second;
				}
			}
		}
		//cout<<dp_un[a]<<"\n";
		for(auto x:G[a]){
			int ind,A,b; 
			tie(ind,b,A)=x;
			if(pare[ind]!=a) continue;
			//cout<<dp_sum[ind]<<" ";
			dp_sum[ind]*=((ll)A*dp_un[a])%mod;
			dp_sum[ind]%=mod;
			dp_sum[ind]=(dp_sum[ind]*jyo((ll)b*dp_un[ind],mod-2,mod))%mod;
			dp_sum[a]=(dp_sum[a]+dp_sum[ind])%mod;
			//cout<<dp_sum[ind]<<"\n";
		}
		//cout<<dp_un[a]<<" "<<dp_sum[a]<<"\n";
		dp_sum[a]=(dp_sum[a]+dp_un[a])%mod;
	}
	//cout<<"ans is .. ";
	cout<<(dp_sum[0]+mod)%mod<<"\n";
}