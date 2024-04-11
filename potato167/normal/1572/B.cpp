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
ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	vector<int> p(n);
	rep(i,n) cin>>p[i];
	int l=-1,r=INF;
	vector<int> ans;
	rep(i,n){
		if(!p[i]){
			if(l==-1){
				r=i;
				continue;
			}
			if((i-l)%2==0){
				for(int j=i-2;j>=l;j-=2){
					ans.push_back(j);
					p[j]=0,p[j+1]=0;
				}
				l=-1;
				r=i;
			}
			else{
				if(i!=n-1){
					ans.push_back(i-1);
					int b=(p[i+1]^1);
					if(b){
						p[i]=1;
						p[i+1]=1;
					}
					else{
						p[i-1]=0;
						p[i+1]=0;
						for(int j=i-3;j>=l;j-=2){
							ans.push_back(j);
							p[j]=0;
							p[j+1]=0;
						}
						l=-1;
					}
				}
				else r=i;
			}
		}
		else{
			if(l==-1) l=i;
		}
	}
	if((n-r-1)%2==0){
		for(int i=r;i<n-2;i+=2){
			ans.push_back(i);
			p[i+1]=0,p[i+2]=0;
		}
	}
	int k=0;
	rep(i,n){
		chmax(k,p[i]);
	}
	if(k==1) cout<<"NO\n";
	else{
		cout<<"YES\n";
		int m=ans.size();
		cout<<m<<"\n";
		rep(i,m){
			if(i!=0) cout<<" ";
			cout<<ans[i]+1;
			if(i==m-1) cout<<"\n";
		}
	}
}