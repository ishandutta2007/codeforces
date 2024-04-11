#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll Q=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
template<class T> void print_tate(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<"\n";}
void yneos(bool a){if(a) cout<<"Yes"<<"\n"; else cout<<"No"<<"\n";}

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


//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T=1;
	

	rep(i,T) solve();
}

void solve(){
	ll N;
	cin>>N;
	vector<vector<int>> G(N);
	rep(i,N-1){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<vector<ll>> kaku(N,vector<ll>(N,0));
	rep(i,N) kaku[0][i]=1;
	rep(i,N-1) rep(j,N-1){
		kaku[i+1][j+1]=((Q/2+1)*(kaku[i+1][j]+kaku[i][j+1]))%Q;
	}
	vector<vector<int>> dis(N,vector<int>(N,-1));
	rep(i,N){
		queue<int> q;
		q.push(i);
		dis[i][i]=0;
		while(!q.empty()){
			int a=q.front();
			q.pop();
			for(auto x:G[a]){
				if(dis[i][x]==-1){
					dis[i][x]=dis[i][a]+1;
					q.push(x);
				}
			}
		}
	}
	//cout<<"I"<<endl;
	ll ans=0;
	rep(i,N){
		for(int j=1+i;j<N;j++){
			int c=dis[i][j];
			ll A=0;
			rep(k,N){
				int a=dis[i][k],b=dis[j][k];
				int d=a+b-c;
				d/=2;
				a-=d,b-=d;
				A+=kaku[b][a];
				A%=Q;
			}
			//cout<<A<<" "<<dis[i][j]<<endl;
			ans+=(A*jyo(N,Q-2,Q))%Q;
			ans%=Q;
		}
	}
	/*rep(i,N){
		rep(j,N) cout<<dis[i][j];
		cout<<endl;
	}*/
	//cout<<"I"<<endl;
	cout<<(ans)%Q<<"\n";
	return ;
}