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
ll mod=1e9+7;
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
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<vector<int>> p(n,vector<int>(n));
	vector<int> A(n*n);
	int V=0;
	rep(i,n) rep(j,n){
		cin>>p[i][j];
		p[i][j]--;
		if(A[p[i][j]]==0) V++;
		A[p[i][j]]++;
	}
	if(k>=V){
		cout<<k-V<<"\n";
		return;
	}
	rep(i,n) rep(j,n){
		if(i!=0&&j!=0) continue;
		int l=0,r=0,tmp=V;
		vector<int> B(n*n);
		while(l+max(i,j)!=n){
			if(l==r||(r+max(i,j)!=n&&tmp>k)){
				rep(a,r-l+1){
					int v=p[i+r][j+l+a];
					B[v]++;
					if(B[v]==A[v]) tmp--;
				}
				rep(a,r-l){
					int v=p[i+l+a][j+r];
					B[v]++;
					if(B[v]==A[v]) tmp--;
				}
				r++;
			}else{
				rep(a,r-l){
					int v=p[i+l][j+l+a];
					if(B[v]==A[v]) tmp++;
					B[v]--;
				}
				rep(a,r-l){
					if(a==0) continue;
					int v=p[i+l+a][j+l];
					if(B[v]==A[v]) tmp++;
					B[v]--;
				}
				l++;
			}
			/*cout<<"\n";
			cout<<i<<" "<<j<<" "<<l<<" "<<r<<" "<<tmp<<"\n";
			vec_out(A),vec_out(B);*/
			if(tmp==k||tmp+1==k){
				/*cout<<i<<" "<<j<<" "<<l<<" "<<r<<"\n";
				vec_out(A),vec_out(B);*/
				cout<<"1\n";
				return ;
			}
		}
	}
	cout<<"2\n";
}