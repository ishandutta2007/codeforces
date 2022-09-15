#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
template<class T> void print_tate(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<"\n";}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

void solve();

//tourist toast
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	rep(i,T) solve();
}

void solve(){
	int n;
	cin>>n;
	vector<int> p(n);
	rep(i,n) cin>>p[i],p[i]--;
	vector<int> match(n,-1);
	vector<int> use_num(n,-1);
	int ans=0;
	rep(i,n){
		if(use_num[p[i]]==-1){
			use_num[p[i]]=i;
			match[i]=p[i];
			ans++;
			//cout<<i<<endl;
		}
	}
	int dou=0;
	rep(i,n){
		if(match[i]+use_num[i]==-2) dou++;
	}
	//cout<<ans<<" "<<dou<<endl;
	if(dou==1){
		rep(i,n){
			if(match[i]+use_num[i]==-2){
				if(ans==n-1){
					match[i]=p[i];
					match[use_num[p[i]]]=i;
					use_num[i]=use_num[p[i]];
					use_num[p[i]]=i;
				}
				else{
					rep(j,n){
						if(j!=i&&use_num[j]==-1){
							match[i]=j;
							use_num[j]=i;
							break;
						}
					}
				}
				break;
			}
		}
	}
	else if(dou>1){
		int last=-1;
		int first=-1;
		rep(i,n){
			if(match[i]+use_num[i]==-2){
				if(last!=-1){
					match[i]=last;
					use_num[last]=i;
				}
				else{
					first=i;
				}
				last=i;
			}
		}
		use_num[last]=first;
		match[first]=last;
	}
	//cout<<ans<<endl;
	int a=0,b=0;
	while(true){
		while(a<n&&match[a]!=-1){
			a++;
		}
		while(b<n&&use_num[b]!=-1) b++;
		if(a==n) break;
		match[a]=b;
		use_num[b]=a;
	}
	cout<<ans<<"\n";
	rep(i,n){
		if(i!=0) cout<<" ";
		cout<<match[i]+1;
	}
	cout<<"\n";
}