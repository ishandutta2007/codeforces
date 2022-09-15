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

namespace po167{
struct UFtree
{
	std::vector<int> wei;
	std::vector<int> q;
	int component;
	UFtree(int n):wei(n),component(n),par(n){
		for(int i=0;i<n;i++){
			wei[i]=1,par[i]=i;
		}
	}
	void intialize(){
		for(auto x:q){
			wei[root(x)]=1;
			par[x]=x;
		}
		component=(int)par.size();
		q={};
	}
	//
	int root(int a){
		if(a==par[a]) return a;
		return par[a]=root(par[a]);
	}
	//true1,false0
	int same(int a,int b){
		if(root(a)==root(b)) return 1;
		else return 0;
	}
	//a,b,true
	bool unite(int a,int b){
		a=root(a),b=root(b);
		if(a==b) return false;
		if(wei[a]<wei[b]) std::swap(a,b);
		par[b]=a;
		q.push_back(b);
		wei[a]+=wei[b];
		component--;
		return true;
	}
	private:
	std::vector<int> par;
};
}
using po167::UFtree;




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
	int H,W;
	cin>>H>>W;
	vector<vector<int>> p(H,vector<int>(W));
	rep(i,H) rep(j,W){
		char c;
		cin>>c; 
		if(c=='?') p[i][j]=-1;
		else p[i][j]=(int)(c-'0');
	}
	if(H%2==0&&W%2==0){
		ll ans=1;
		rep(i,H) rep(j,W){
			if(p[i][j]==-1) ans=(ans*2ll)%mod;
		}
		cout<<ans<<"\n";
		return ;
	}
	if(W%2==0){
		vector<vector<int>> q(W,vector<int>(H));
		rep(i,H) rep(j,W) q[j][i]=p[i][j];
		swap(p,q);
		swap(H,W);
	}
	if(H%2==0){
		vector<int> q(H),K(H);
		vector<int> r(2);
		rep(i,H){
			rep(j,W){
				if(p[i][j]!=-1&&q[i]!=-1){
					q[i]^=p[i][j];
				}
				if(p[i][j]==-1) K[i]++,q[i]=-1;
			}
			if(q[i]!=-1) r[q[i]]++;
		}
		if(r[0]!=0&&r[1]!=0){
			cout<<"0\n";
		}else if(r[0]==0&&r[1]==0){
			int X=1;
			rep(i,H) X+=K[i]-1;
			cout<<jyo(2,X,mod)<<"\n";
		}else{
			int X=0;
			rep(i,H) X+=max(0,K[i]-1);
			cout<<jyo(2,X,mod)<<"\n";
		}
	}else{
		UFtree T(H+W);
		int X=0;
		vector<int> A(H+W);
		rep(i,H) rep(j,W){
			if(p[i][j]==-1){
				if(!T.unite(i,j+H)) X++;
			}else{
				A[i]^=p[i][j];
				A[H+j]^=p[i][j];
			}
		}
		rep(i,H+W){
			if(T.root(i)!=i){
				A[T.root(i)]^=A[i];
			}
		}
		int Z=0,Y=0;
		rep(i,H+W){
			if(T.root(i)!=i) continue;
			if(T.wei[i]%2==0){
				if(A[i]) Z=1,Y=1;
			}else{
				if(A[i]) Z=1;
				else Y=1;
			}
		}
		if(Z*Y==1) cout<<"0\n";
		else if(Z+Y) cout<<jyo(2,X,mod)<<"\n";
		else cout<<jyo(2,X+1,mod)<<"\n";
	}
}