
// Problem : C. Perfect Keyboard
// Contest : Educational Codeforces Round 82 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1303/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

const int L=26;
vector<vector<int> > graf(L);
string sol;
vector<int> visited(L);
void dfs(int i){
	sol+='a'+i;
	visited[i]=1;
	for(auto p:graf[i])
		if(!visited[p])
			dfs(p);
}
bool moze[L][L];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t;
	scanf("%i",&t);
	while(t--){
		string s;
		cin >> s;
		int n=s.size();
		fill(all(visited),0);
		memset(moze,0,sizeof(moze));
		for(int i=0;i<n-1;i++)
			moze[s[i]-'a'][s[i+1]-'a']=moze[s[i+1]-'a'][s[i]-'a']=1;
		sol.clear();
		for(int i=0;i<L;i++)
			graf[i].clear();
		for(int i=0;i<L;i++)
			for(int j=0;j<L;j++)
				if(moze[i][j])
					graf[i].pb(j);
		vector<pair<int,int> > cnt;
		for(int i=0;i<L;i++)
			cnt.pb({graf[i].size(),i});
		sort(all(cnt));
		if(cnt[L-1].f>2){
			printf("NO\n");
			continue;
		}
		vector<int> cnt1;
		for(int i=0;i<L;i++)
			if(cnt[i].f==1)
				cnt1.pb(cnt[i].s);
		if(cnt[L-1].f==2&&cnt1.size()<2){
			printf("NO\n");
			continue;
		}
		for(int i=0;i<L;i++){
			if(graf[i].size()==2||visited[i])
				continue;
			dfs(i);
		}
		cout << "YES\n" << sol << endl;
	}
	return 0;
}