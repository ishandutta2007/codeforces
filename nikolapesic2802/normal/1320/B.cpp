
// Problem : B. Navigation System
// Contest : Codeforces Round #625 (Div. 1, based on Technocup 2020 Final Round)
// URL : http://codeforces.com/contest/1320/problem/B
// Memory Limit : 512 MB
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

const int N=2e5+5;
vector<vector<int> > graf(N);
vector<int> dist(N),cnt(N);
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%i %i",&a,&b);
		a--;b--;
		graf[b].pb(a);
	}
	int k;
	scanf("%i",&k);
	vector<int> p(k);
	for(int i=0;i<k;i++)
		scanf("%i",&p[i]),p[i]--;
	int t=p[k-1];
	dist[t]=1;
	cnt[t]=1;
	queue<int> q;
	q.push(t);
	while(q.size()){
		int tr=q.front();
		q.pop();
		for(auto p:graf[tr]){
			if(dist[p]==0){
				dist[p]=dist[tr]+1;
				q.push(p);
			}
			if(dist[p]==dist[tr]+1)
				cnt[p]++;
		}
	}
	/*for(int i=0;i<n;i++)
		printf("%i: %i\n",i+1,dist[i]);*/
	int mn=0,mx=0;
	for(int i=0;i<k-1;i++){
		int a=p[i],b=p[i+1];
		if(dist[b]!=dist[a]-1)
			mn++;
		if(dist[b]!=dist[a]-1||cnt[a]>1)
			mx++;
	}
	printf("%i %i\n",mn,mx);
	return 0;
}