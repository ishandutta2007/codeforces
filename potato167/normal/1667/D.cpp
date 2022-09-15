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



void solve();
// oddloop
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
	std::vector<std::vector<int>> G(n);
	for(int i=0;i<n-1;i++){
		int a;int b;
		cin>>a>>b; 
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int root=0;
	std::vector<int> order={root},pare(n,-1),depth(n);
	pare[root]=-2;
	for(int i=0;i<n;i++){
		int a=order[i];
		for(auto x:G[a]){
			if(pare[x]==-1){
				pare[x]=a;
				depth[x]=depth[a]+1;
				order.push_back(x);
			}
		}
	}
	vector<int> dp1(n);
	vector<int> p(n);
	vector<vector<int>> H(n);
	vector<int> ind(n);
	vector<int> s;
	int s_ind=0;
	for(int i=n-1;i>=0;i--){
		int a=order[i];
		for(auto x:G[a]){
			if(pare[x]==a){
				dp1[a]+=dp1[x];
			}
		}
		if(((int)(G[a].size())+depth[a])%2){
			dp1[a]++,p[a]=1;
			s.push_back(a);
		}
		if(depth[a]%2) dp1[a]--;
	}
	rep(i,n){
		if(abs(dp1[i])!=min(1,i)){
			cout<<"NO\n";
			return ;
		}
		if(i){
			if(dp1[i]==1){
				H[i].push_back(pare[i]);
			}else{
				H[pare[i]].push_back(i);
			}
		}
	}
	cout<<"YES\n";
	int C=0;
	vector<int> X;
	while((int)s.size()!=s_ind){
		int a=s[s_ind];
		s_ind++;
		if((int)H[a].size()==ind[a]){
			continue;
		}
		X={a};
		int tmp=a;
		do{
			C++;
			assert(C<n);
			int ne=H[tmp][ind[tmp]];
			X.push_back(ne);
			ind[tmp]++;
			tmp=ne;
		}while(p[tmp]);
		swap(p[a],p[tmp]);
		s.push_back(tmp);
		for(int i=(int)X.size()-1;i>0;i--){
			cout<<X[i]+1<<" "<<X[i-1]+1<<"\n";
		}
	}
}