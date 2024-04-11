
// Problem : E. Tree Queries
// Contest : Codeforces Round #629 (Div. 3)
// URL : https://codeforces.com/contest/1328/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double
#define li __int128

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
template<class T1, class T2> istream& operator>>(istream& is,pair<T1,T2>& a) {is>>a.f>>a.s;return is;}
template<class T> istream& operator>>(istream& is,vector<T>& a) {for(auto &p:a)is>>p;return is;}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;for(auto p:s)a=a*10+p-'0';return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

const int N=2e5+5,L=19;
vector<vector<int> > graf(N);
int up[N][L],dep[N];
void dfs(int tr,int par){
	for(auto p:graf[tr])
		if(p!=par)
			dep[p]=dep[tr]+1,up[p][0]=tr,dfs(p,tr);
}
int lca(int a,int b){
	if(dep[a]<dep[b])
		swap(a,b);
	for(int j=L-1;j>=0;j--){
		if(dep[a]-dep[b]>=(1<<j))
			a=up[a][j];
	}
	if(a==b)
		return a;
	for(int j=L-1;j>=0;j--)
		if(up[a][j]!=up[b][j])
			a=up[a][j],b=up[b][j];
	return up[a][0];
}
int main()
{
	int n,m;
	cin >> n>> m;
	for(int i=1;i<n;i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	dfs(0,0);
	for(int j=1;j<L;j++){
		for(int i=0;i<n;i++){
			up[i][j]=up[up[i][j-1]][j-1];
		}
	}
	for(int i=0;i<m;i++){
		int k;
		cin >> k;
		vector<int> v(k);
		cin >> v;
		for(auto &p:v)
			p--;
		for(auto &p:v)
			if(p!=0)
				p=up[p][0];
		vector<pair<int,int> > ok;
		for(auto p:v)
			ok.pb({dep[p],p});
		sort(ok.rbegin(),ok.rend());
		//cout << ok << endl;
		bool okk=1;
		for(int i=1;i<k;i++){
			if(lca(ok[i].s,ok[0].s)!=ok[i].s){
				printf("NO\n");
				okk=0;
				break;
			}
		}
		if(okk)
			printf("YES\n");
	}
	return 0;
}