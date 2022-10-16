
// Problem : E. Treeland and Viruses
// Contest : Codeforces Round #625 (Div. 1, based on Technocup 2020 Final Round)
// URL : https://codeforces.com/contest/1320/problem/E
// Memory Limit : 512 MB
// Time Limit : 3000 ms
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


const int N=2e5+5,L=18;
vector<vector<int> > drvo(N),up(N,vector<int>(L));
vector<vector<pair<int,int> > > graf(N);
vector<int> dep(N),in(N);
vector<pair<int,int> > dist(N);
int t;
void init(int tr,int par){
	in[tr]=t++;
	for(auto p:drvo[tr])
		if(p!=par)
			dep[p]=dep[tr]+1,up[p][0]=tr,init(p,tr);
}
int lca(int a,int b){
	if(dep[a]<dep[b])
		swap(a,b);
	for(int j=L-1;j>=0;j--)
		if(dep[a]-dep[b]>=1<<j)
			a=up[a][j];
	if(a==b)
		return a;
	for(int j=L-1;j>=0;j--)
		if(up[a][j]!=up[b][j])
			a=up[a][j],b=up[b][j];
	return up[a][0];
}
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%i %i",&a,&b);
		a--;b--;
		drvo[a].pb(b);
		drvo[b].pb(a);
	}
	init(0,0);
	for(int j=1;j<L;j++)
		for(int i=0;i<n;i++)
			up[i][j]=up[up[i][j-1]][j-1];
	int q;
	scanf("%i",&q);
	while(q--){
		//printf("%i!\n",q);
		int k,m;
		scanf("%i %i",&k,&m);
		set<int> tacke;
		vector<pair<int,int> > virus;
		for(int i=0;i<k;i++){
			int x,s;
			scanf("%i %i",&x,&s);
			x--;
			virus.pb({x,s});
			tacke.insert(x);
		}
		vector<int> important;
		for(int i=0;i<m;i++){
			int x;
			scanf("%i",&x);
			x--;
			tacke.insert(x);
			important.pb(x);
		}
		vector<pair<int,int> > tt;
		for(auto p:tacke)
			tt.pb({in[p],p});
		sort(all(tt));
		//cout << tt << endl;
		for(int i=0;i<(int)tt.size()-1;i++)
			tacke.insert(lca(tt[i].s,tt[i+1].s));
		vector<int> stk;
		tt.clear();
		for(auto p:tacke){
			tt.pb({in[p],p});
			graf[p].clear();
			dist[p]={INT_MAX,INT_MAX};
		}
		sort(all(tt));
		//cout << tt << endl;
		stk.pb(tt[0].s);
		for(int i=1;i<(int)tt.size();i++){
			int p=tt[i].s;
			while(lca(stk.back(),p)!=stk.back())
				stk.pop_back();
			int d=dep[p]-dep[stk.back()];
			graf[p].pb({stk.back(),d});
			graf[stk.back()].pb({p,d});
			//printf("%i-%i  %i\n",p,stk.back(),d);
			stk.pb(p);
		}
		set<pair<pair<int,int>,pair<int,int> > > q;
		for(int i=0;i<k;i++){
			int x=virus[i].f;
			dist[x]={-1,i};
			q.insert({dist[x],{x,virus[i].s-1}});
		}
		while(q.size()){
			pair<int,int> d=(*q.begin()).f;
			int tr=(*q.begin()).s.f,s=(*q.begin()).s.s;
			int brzina=virus[d.s].s;
			q.erase(q.begin());
			if(d!=dist[tr])
				continue;
			//printf("%i:  %i  %i    %i\n")
			for(auto p:graf[tr]){
				pair<int,int> noviD=d;
				int noviS=s+p.s;
				noviD.f+=noviS/brzina;
				noviS%=brzina;
				if(noviD<dist[p.f]){
					dist[p.f]=noviD;
					q.insert({dist[p.f],{p.f,noviS}});
				}
			}
		}
		for(int i=0;i<m;i++){
			printf("%i ",dist[important[i]].s+1);
		}
		printf("\n");
	}
	return 0;
}