
// Problem : D. Kuroni and the Celebration
// Contest : Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!)
// URL : https://codeforces.com/contest/1305/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

const int N=1e3+5;
vector<vector<int> > graf(N);
vector<int> done(N),dist(N),par(N);
int n;
void dfs(int tr,int pa){
	for(auto p:graf[tr])
		if(!done[p]&&p!=pa)
			dist[p]=dist[tr]+1,par[p]=tr,dfs(p,tr);
}
pair<int,int> findDiam(int tr){
    //printf("%i!\n",tr);
	fill(all(dist),-1);
	dist[tr]=0;
	dfs(tr,tr);
	//cout << dist << endl;
	int mx=0,gde=tr;
	for(int i=0;i<n;i++)
		if(!done[i]&&dist[i]>mx)
			mx=dist[i],gde=i;
	tr=gde;
	fill(all(dist),-1);
	fill(all(par),-1);
	dist[tr]=0;
	dfs(tr,tr);
	mx=0,gde=tr;
	for(int i=0;i<n;i++)
		if(!done[i]&&dist[i]>mx)
			mx=dist[i],gde=i;
	return {tr,gde};
}
int siz(int tr,int par){
	int s=1;
	for(auto p:graf[tr])
		if(!done[p]&&p!=par)
			s+=siz(p,tr);
	return s;
}
int cnt=0;
void solve(int tr){
	if(siz(tr,tr)==1){
		printf("! %i\n",tr+1);
		exit(0);
	}
	pair<int,int> ok=findDiam(tr);
	printf("? %i %i\n",ok.f+1,ok.s+1);
	fflush(stdout);
	cnt++;
	assert(cnt<=n/2);
	int w;
	scanf("%i",&w);
	if(w==-1){
        exit(0);
	}
	w--;
	vector<int> diam;
	diam.pb(ok.s);
	while(par[ok.s]!=-1)
		ok.s=par[ok.s],diam.pb(ok.s);
	//cout << diam << endl;
	for(auto p:diam)
		if(p!=w)
			done[p]=1;
	solve(w);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%i",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%i %i",&a,&b);
		a--;b--;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	solve(0);
	return 0;
}