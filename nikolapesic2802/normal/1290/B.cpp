
// Problem : B. Irreducible Anagrams
// Contest : Codeforces Round #616 (Div. 1)
// URL : https://codeforces.com/contest/1290/problem/B
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

bool anag(string a,string b){
	vector<int> cnt(26);
	for(auto p:a)
		cnt[p-'a']++;
	for(auto p:b)
		cnt[p-'a']--;
	for(auto p:cnt)
		if(p!=0)
			return 0;
	return 1;
}
bool iranagram(string a,string b){
	int n=a.size();
	for(int i=0;i<n-1;i++){
		if(anag(a.substr(0,i+1),b.substr(0,i+1)))
			return 1;
	}
	return 0;
}
bool test(string a){
	vector<char> ok;
	for(auto p:a)
		ok.pb(p);
	do{
		string s;
		for(auto p:ok)
			s+=p;
		if(!iranagram(a,s))
			return 1;
	}while(next_permutation(all(ok)));
	return 0;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string s;
	cin >> s;
	int n=s.size();
	vector<vector<int> > sum(n,vector<int>(26));
	for(int i=0;i<n;i++)
		sum[i][s[i]-'a']++;
	for(int i=1;i<n;i++)
		for(int j=0;j<26;j++)
			sum[i][j]+=sum[i-1][j];
	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		int l,r;
		cin >> l >> r;
		if(l==r||s[l-1]!=s[r-1]){
			printf("Yes\n");
			continue;
		}
		int cnt=0;
		for(int j=0;j<26;j++){
			int s=sum[r-1][j];
			if(l-1)
				s-=sum[l-2][j];
			if(s)
				cnt++;
		}
		if(cnt>2)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}