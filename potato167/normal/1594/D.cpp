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
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> G(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--,b--;
		string S;
		cin>>S;
		int c=0;
		if(S[0]=='i') c=1;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}
	vector<int> seen(n,-1);
	int ans=0;
	rep(i,n){
		if(seen[i]!=-1) continue;
		int A=0,B=0,J=0;
		queue<int> q;
		q.push(i);
		seen[i]=0;
		while(!q.empty()){
			int a=q.front();
			//cout<<a<<" "<<seen[a]<<"\n";
			q.pop();
			if(seen[a]) A++;
			else B++;
			for(auto x:G[a]){
				if(seen[x.first]==-1){
					seen[x.first]=(seen[a]^x.second);
					q.push(x.first);
				}else if(seen[x.first]!=(seen[a]^x.second)){
					cout<<"-1\n";
					return;
				}
			}
		}
		ans+=max(A,B);
	}
	cout<<ans<<"\n";
}