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
#define rep(i,a) for (int i=0;i<a;i++)
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
	vector<int> p(n);
	rep(i,n) cin>>p[i],p[i]--;
	vector<int> q(n);
	rep(i,n) q[p[i]]=i;
	vector<vector<int>> G;
	int ind=0;
	while(true){
		bool T=1;
		int x=0;
		G.push_back({});
		rep(i,n-1){
			if(q[i]>q[i+1]){
				if(q[i+1]) G[ind].push_back(q[i+1]);
				int tmp=q[i+1];
				while(true){
					if(p[tmp]>p[tmp+1]){
						G[ind].push_back(tmp+1-q[i+1]);
						break;
					}
					tmp++;
				}
				G[ind].push_back(q[i]-tmp);
				if(q[i]!=n-1) G[ind].push_back(n-1-q[i]);
				T=0;
				break;
			}
		}
		if(T) break;
		x=0;
		for(auto y:G[ind]){
			reverse(p.begin()+x,p.begin()+x+y);
			x+=y;
		}
		reverse(p.begin(),p.end());
		rep(i,n) q[p[i]]=i;
		/*rep(i,n) cout<<p[i]<<" ";
		cout<<endl;*/
		ind++;
	}
	cout<<G.size()-1<<"\n";
	for(auto x:G){
		if(x.size()==0) break;
		cout<<x.size();
		for(auto y:x) cout<<" "<<y;
		cout<<"\n";
	}
}