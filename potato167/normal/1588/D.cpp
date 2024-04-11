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
	
	int t;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	vector<vector<int>> p(n);
	int M=52;
	vector<vector<vector<int>>> table(n,vector<vector<int>>(M*2,vector<int>(M,-1)));
	vector<vector<int>> rev(n,vector<int>(M*2,INF));
	rep(i,n){
		string S;
		cin>>S;
		rep(j,S.size()){
			int a=S[j]-'a';
			if(a<0||26<=a) a=S[j]-'A',a+=26;
			p[i].push_back(a);
			if(rev[i][a]==INF) rev[i][a]=j;
			else rev[i][a+M]=j;
		}
		rep(j,M*2) rep(k,M){
			if(rev[i][j]>rev[i][k+M]) table[i][j][k]=1;
			else if(rev[i][j]>rev[i][k]) table[i][j][k]=0;
		}
	}
	vector<vector<int>> dp(M,vector<int>(1<<n,-1));
	vector<vector<int>> dp_sub(M,vector<int>(1<<n,-1));
	vector<vector<int>> front(M,vector<int>(1<<n,-1));
	vector<vector<int>> front_sub(M,vector<int>(1<<n,-1));
	int ans=0;
	int start=-1;
	//cout<<endl;
	rep(ind,p[0].size()){
		//cout<<ans<<endl;
		int c=p[0][ind];
		int D=0;
		if(rev[0][c]!=ind) D++;
		//cout<<rev[0][c]<<endl;
		//cout<<D<<endl;
		rep(r,(1<<(n-1))){
			int b=r*2+D;
			int tmp=1;
			rep(k,n){
				int z=0;
				if(b&(1<<k)) z=1;
				if(rev[k][z*M+c]==INF){
					tmp=-1;
					break;
				}
			}
			if(tmp==-1) continue;
			dp[c][b]=1;
			rep(cha,M){
				int x=0;
				rep(k,n){
					int z=0;
					if(b&(1<<k)) z=1;
					if(table[k][z*M+c][cha]==-1){
						x=-1;
						break;
					}else{
						x+=table[k][z*M+c][cha]*(1<<k);
					}
				}
				if(x>=0){
					if(chmax(dp[c][b],1+dp_sub[cha][x])){
						front[c][b]=front_sub[cha][x];
					}
				}
			}
			if(chmax(ans,dp[c][b])) start=c+b*M;
			int T=(1<<n)-1;
			T^=b;
			for(int U=T;U>=0;U--){
				U&=T;
				if(chmax(dp_sub[c][U^b],dp[c][b])){
					front_sub[c][U^b]=(c+M*b);
				};
			}
		}
	}
	cout<<ans<<"\n";
	string T="";
	rep(i,ans){
		int c=start%M;
		int b=start/M;
		if(c<26) T+=(char)('a'+c);
		else T+=(char)('A'+c-26);
		start=front[c][b];
	}
	reverse(T.begin(),T.end());
	cout<<T<<"\n";
}