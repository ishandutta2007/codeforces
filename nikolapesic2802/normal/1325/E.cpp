
// Problem : E. Ehab's REAL Number Theory Problem
// Contest : Codeforces Round #628 (Div. 2)
// URL : https://codeforces.com/contest/1325/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

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

const int N=1e6+1,M=1e3+1;
vector<vector<int> > graf(N);
vector<int> d(N,1);
vector<int> imaSingle(N);
vector<int> q(N),par(N),dist(N,-1);
int sol=N;
int l,r;
void bfs(int st){
	l=r=0;
	dist[st]=0;
	par[st]=-1;
	q[r++]=st;
	int mn1=N,mn2=N;
	while(l!=r){
		int tr=q[l++];
		if(imaSingle[tr]){
			if(mn1==N)
				mn1=dist[tr];
			else
				if(mn2==N)
					mn2=dist[tr];
		}
		for(auto p:graf[tr]){
			if(dist[p]==-1)
				dist[p]=dist[tr]+1,q[r++]=p,par[p]=tr;
			else{
				if(p!=par[tr]){
					sol=min(sol,dist[tr]+dist[p]+1);
				}
			}
		}
	}
	sol=min(sol,mn1+mn2+2);
	for(int i=0;i<r;i++)
		dist[q[i]]=-1;
}
int main()
{
	for(int i=2;i<N;i++){
		if(d[i]==1){
			for(int j=i;j<N;j+=i)
				d[j]=i;
		}
	}
	int n;
	scanf("%i",&n);
	vector<int> a(n);
	for(int i=0;i<n;i++){
		scanf("%i",&a[i]);
		if(a[i]==1){
			printf("1\n");
			return 0;
		}
		map<int,int> divs;
		int b=a[i];
		while(b>1){
			divs[d[b]]++;
			b/=d[b];
		}
		if(divs.size()==1){
			for(auto p:divs){
				if(p.s&1){
						imaSingle[p.f]++;
				}
				else{
					printf("1\n");
					return 0;
				}
			}
		}
		else{
			vector<int> f;
			for(auto p:divs){
				if(p.s&1)
					f.pb(p.f);
			}
			if(f.empty()){
				printf("1\n");
				return 0;
			}
			if(f.size()==1)
				imaSingle[f[0]]++;
			else{
				assert(f.size()==2);
				//imaSingle[f[0]*f[1]]++;
				graf[f[0]].pb(f[1]);
				graf[f[1]].pb(f[0]);
			}
		}
	}
	for(auto p:imaSingle){
		if(p>1){
			printf("2\n");
			return 0;
		}
	}
	for(int i=0;i<M;i++){
		if(graf[i].size())
			bfs(i);
	}
	if(sol==N)
		sol=-1;
	printf("%i\n",sol);
	return 0;
}