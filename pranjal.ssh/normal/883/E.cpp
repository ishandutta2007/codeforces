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
	int n,m;string s;
	set<char> poss,ss;
	cin>>n>>s>>m;
	for(auto i:s)
		if(i!='*')
			ss.insert(i);
	for(auto i='a';i<='z';i++)
		poss.insert(i);
	for(auto i:ss)
		poss.erase(i);
	FOR(z,1,m)
	{
		bool flag=0;
		string t;
		cin>>t;
		FOR(i,0,n-1)
		if(s[i]=='*')
		{
			for(auto j:ss)
				if(t[i]==j)
					{flag=1;break;}
			if(flag) break;
		}
		else if(s[i]!=t[i])
			{flag=1;break;}
		if(!flag)
		{
			set<char> st;
			for(auto i:t)
				st.insert(i);
			for(auto i='a';i<='z';i++)
				if(st.find(i)==st.end())
					poss.erase(i);
		}
	}
	cout<<poss.size();
}