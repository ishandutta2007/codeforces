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
ll Q=998244353;
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



//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;
	vector<ll> input(N);
	vector<pair<ll,ll>> p;
	rep(i,N){
		char a;
		cin>>a;
		if(a=='-') input[i]=-1;
		else {
			ll b=0;
			cin>>b;
			input[i]=b;
			p.push_back({b,i});
		}
	}
	So(p);
	int M=p.size();
	vector<ll> order(N,-1);
	rep(i,M) order[p[i].second]=i;
	vector<vector<ll>> dp1(M,vector<ll>(M+1,0));
	rep(i,M) dp1[i][0]=1;
	auto dp2=dp1;
	rep(i,N){
		if(input[i]==-1){
			rep(j,M) rep(k,j+1){
				if(k==0) dp1[j][k]+=dp1[j][k],dp2[j][k]+=dp2[j][k];
				dp1[j][k]+=dp1[j][k+1];
				dp2[j][k]+=dp2[j][k+1];
				dp1[j][k]%=Q;
				dp2[j][k]%=Q;
			}
		}
		else{
			int ind=order[i];
			rep(j,M) for(int k=j+1;k>=0;k--){
				if(j<ind){
					dp1[j][k]*=2;
					dp2[j][k]*=2;
					dp1[j][k]%=Q;
					dp2[j][k]%=Q;
				}
				else{
					if(k==0){
						if(j!=ind) dp1[j][k]*=2;
						dp1[j][k]%=Q;
					}
					else{
					if(j==ind){
						if(k!=0){
							dp1[j][k]+=dp2[j][k-1];
							dp1[j][k]%=Q;
						}
					}
					else{
						if(k!=1){
							dp1[j][k]+=dp1[j][k-1];
							dp1[j][k]%=Q;
						}
					}
					if(k!=0){
						dp2[j][k]+=dp2[j][k-1];
						dp2[j][k]%=Q;
					}
					}
				}
			}
		}
		/*rep(j,M){
			rep(k,M+1) cout<<dp1[j][k]<<" ";
			cout<<" ";
			rep(k,M+1) cout<<dp2[j][k]<<" ";
			cout<<endl;
		}
		cout<<endl;*/
	}
	ll ans=0;
	ll sum=1;
	rep(i,N) sum*=2,sum%=Q;
	rep(i,M){
		//cout<<dp1[i][0]<<endl;
		ans+=(((sum-dp1[i][0])%Q)*p[i].first)%Q;
		ans%=Q;
	}
	cout<<(Q+ans%Q)%Q<<endl;
}