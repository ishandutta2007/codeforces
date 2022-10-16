
// Problem : G. Autocompletion
// Contest : Educational Codeforces Round 83 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1312/problem/G
// Memory Limit : 512 MB
// Time Limit : 7000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

struct node{
	vector<int> nxt;
	int cnt;
	int endId;
	vector<int> dp;
	node(){
		nxt.resize(26,-1);
		cnt=0;
		endId=-1;
		dp.resize(2);
	}
}em;
vector<node> trie(1);
const int N=1e6+1;
vector<int> ans(N);
void init(int tr){
	for(int i=0;i<26;i++)
		if(trie[tr].nxt[i]!=-1)
			init(trie[tr].nxt[i]),trie[tr].cnt+=trie[trie[tr].nxt[i]].cnt;
}
vector<char> trStr;
void doDp(int tr){
	//cout << trStr << trie[tr].dp << endl;
	if(trie[tr].endId!=-1){
		ans[trie[tr].endId]=min(trie[tr].dp[0],trie[tr].dp[1]);
	}
	int cnt=0;
	for(int i=0;i<26;i++){
		if(trie[tr].nxt[i]==-1)
			continue;
		int sl=trie[tr].nxt[i];
		trie[sl].dp[0]=trie[sl].dp[1]=INT_MAX;
		trie[sl].dp[0]=trie[tr].dp[0]+1;
		if(trie[tr].endId!=-1)
			trie[sl].dp[0]=min(trie[sl].dp[0],trie[tr].dp[1]+1);
		trie[sl].dp[1]=min(trie[tr].dp[0]+cnt+1,trie[tr].dp[1]+cnt);
		if(trie[tr].endId!=-1)
			trie[sl].dp[1]++;
		trStr.pb(i+'a');
		doDp(sl);
		trStr.pop_back();
		cnt+=trie[sl].cnt;
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int p;
		char c;
		cin >> p >> c;
		int tr=c-'a';
		trie.pb(em);
		trie[p].nxt[tr]=trie.size()-1;
	}
	int k;
	cin >> k;
	for(int i=0;i<k;i++){
		int p;
		cin >> p;
		trie[p].cnt++;
		trie[p].endId=i;
	}
	init(0);
	trie[0].endId=k;
	doDp(0);
	for(int i=0;i<k;i++)
		printf("%i ",ans[i]);
	return 0;
}