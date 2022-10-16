
// Problem : F2. Animal Observation (hard version)
// Contest : Codeforces Round #620 (Div. 2)
// URL : http://codeforces.com/contest/1304/problem/F2
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=51,M=2e4+1;
ll dp[N][M],mx[4*M],lazy[4*M];
void prop(int i){
	lazy[2*i]+=lazy[i];
	lazy[2*i+1]+=lazy[i];
	mx[2*i]+=lazy[i];
	mx[2*i+1]+=lazy[i];
	lazy[i]=0;
}
void add(int qs,int qe,ll x,int l=0,int r=M-1,int i=1){
	/*if(i==1)
		printf("%i %i %lld\n",qs,qe,x);*/
	if(qs>r||qe<l||qs>qe)
		return;
	if(qs<=l&&qe>=r){
		mx[i]+=x;
		lazy[i]+=x;
		return;
	}
	prop(i);
	int m=(l+r)>>1;
	add(qs,qe,x,l,m,2*i);
	add(qs,qe,x,m+1,r,2*i+1);
	mx[i]=max(mx[2*i],mx[2*i+1]);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m,k;
	scanf("%i %i %i",&n,&m,&k);
	int cnt[n][m];
	int cntSum[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%i",&cnt[i][j]),cntSum[i][j]=cnt[i][j];
	for(int i=0;i<n;i++)
		for(int j=1;j<m;j++)
			cntSum[i][j]+=cntSum[i][j-1];
	for(int i=n-1;i>0;i--){
		memset(mx,0,sizeof mx);
		memset(lazy,0,sizeof lazy);
		if(i!=n-1){
			for(int j=0;j<m;j++)
				add(j,j,dp[i+1][j]),add(j-k+1,j,cnt[i+1][j]);
		}
		for(int j=k;j<m;j++)
			add(j-k+1,j,cnt[i][j]);
		for(int j=0;j<m;j++){
			dp[i][j]=mx[1];
			//printf("dp[%i][%i]:%i\n",i,j,dp[i][j]);
			add(j-k+1,j,cnt[i][j]);
			if(j+k<m)
				add(j+1,j+k,-cnt[i][j+k]);
		}
	}
	memset(mx,0,sizeof mx);
	memset(lazy,0,sizeof lazy);
	if(n!=1)
		for(int j=0;j<m;j++)
			add(j,j,dp[1][j]);
	for(int j=0;j<m;j++){
		add(j-k+1,j,cnt[0][j]);
		if(n!=1)
			add(j-k+1,j,cnt[1][j]);
	}
	printf("%i\n",mx[1]);
	return 0;
}