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

vi v[300009],w[300009];
int T[300009],A[300009],B[300009];
bool mark1[300009],mark2[300009];
map<pii,int> M1,M2;
int ans1,ans2;

void dfs1(int x)
{
	mark1[x]=1;
	ans1++;
	for(auto i:v[x])
		if(!mark1[i])
			dfs1(i);
	for(auto i:w[x])
		M1[mp(i,x)]=M1[mp(x,i)]=x;
}

void dfs2(int x)
{
	mark2[x]=1;
	ans2++;
	for(auto i:v[x])
		if(!mark2[i])
			dfs2(i);
	for(auto i:w[x])
		if(M2[mp(i,x)]!=x && !mark2[i])
		{
			M2[mp(i,x)]=M2[mp(x,i)]=i;
			dfs2(i);
		}
}
int main()
{
	fastio;
	int n,m,s;
	cin>>n>>m>>s;
	FOR(i,1,m)
	{
		int t,a,b;
		cin>>t>>a>>b;
		T[i]=t,A[i]=a,B[i]=b;
		if(t==2)
			w[a].pb(b),w[b].pb(a);
		else v[a].pb(b);
	}
	// mark1[x]=1;
	dfs1(s);
	dfs2(s);
	cout<<ans2<<endl;
	FOR(i,1,m)
	if(T[i]==2)
	{
		if(M2[mp(A[i],B[i])]==B[i])
			cout<<"+";
		else cout<<"-";
	}
	cout<<endl;
	cout<<ans1<<endl;
	FOR(i,1,m)
	if(T[i]==2)
	{
		if(M1[mp(A[i],B[i])]==B[i])
			cout<<"+";
		else cout<<"-";
	}
	cout<<endl;
}