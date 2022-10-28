#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define NFOR(i,a,b) for(int i = (int)(a); i >= (int)(b); --i)
#define endl "\n"
#define mp make_pair
#define X first
#define Y second
#define inf 1e18
#define mod 1000000007
#define pb push_back
#define Case cout<<"Case "<<++cas<<": ";
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(v) v.begin(),v.end()
#define sz(x) int(x.size())
// #define lli __int128
typedef long long int lli;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef pair<lli,lli> pll;
typedef vector<lli> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

int main()
{
	fastio;
	int n;
	cin>>n;
	vi A(n+1),B(n+1),C(n+1),D(n+1),E(n+1);
	FOR(i,1,n)
	{
		int s,g;
		cin>>s>>g;
		A[i]=s,B[i]=s+g;
	}
	C[1]=mod;
	FOR(i,1,n-1)
	C[i+1]=B[i]-i+1;
	FOR(i,2,n)
	C[i]=min(C[i-1],C[i]);
	// pr(C);
	D[n]=mod;
	for(int i=n-1;i>=1;i--)
		D[i]=B[i+1]-(n-i)+1;
	for(int i=n-1;i>=1;i--)
		D[i]=min(D[i+1],D[i]);
	// pr(D);
	FOR(i,1,n)
	E[i]=min(B[i],min(C[i]+i-1,D[i]+(n-i)));
	bool flag=0;
	FOR(i,1,n)
	if(E[i]<A[i] || E[i]>B[i])
		{flag=1;break;}
	if(flag)
		cout<<-1;
	else
	{
		ll ans=0;
		FOR(i,1,n)
		ans+=E[i]-A[i];
		cout<<ans<<endl;
		FOR(i,1,n)
		cout<<E[i]<<" ";
	}
}