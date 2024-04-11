
// Problem : C. Prefix Enlightenment
// Contest : Codeforces Round #616 (Div. 1)
// URL : https://codeforces.com/contest/1290/problem/C
// Memory Limit : 256 MB
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

const int N=3e5+5;
vector<vector<pair<int,int> > > graf(N);
vector<int> on(N,-1);
vector<vector<int> > inds(N);
int cnt=0;
void dfs(int tr){
	for(auto p:graf[tr]){
		if(on[p.f]<0){
			if((on[tr]^p.s)==1)
				cnt++;
			on[p.f]=on[tr]^p.s;
			dfs(p.f);
		}	
	}
}
vector<int> par(N),c1(N,1),c2(N);
vector<vector<int> > nod(N);
int find(int tr){return tr==par[tr]?tr:par[tr]=find(par[tr]);}
void merge(int a,int b,int isti){
	int aa=find(a),bb=find(b);
	if(aa==bb){
		return;
	}
	if(nod[aa].size()<nod[bb].size())
		swap(aa,bb),swap(a,b);
	int flip;
	if(on[a]==on[b])
		if(isti)
			flip=0;
		else
			flip=1;
	else
		if(isti)
			flip=1;
		else
			flip=0;
	cnt-=min(c1[aa],c2[aa])+min(c1[bb],c2[bb]);
	if(flip){
		c1[aa]+=c2[bb];
		c2[aa]+=c1[bb];
		for(auto p:nod[bb])
			nod[aa].pb(p),on[p]=(on[p]==-1?-2:-1);
	}
	else{
		c1[aa]+=c1[bb];
		c2[aa]+=c2[bb];
		for(auto p:nod[bb])
			nod[aa].pb(p);
	}
	par[bb]=aa;
	cnt+=min(c1[aa],c2[aa]);
}
int main()
{
	iota(all(par),0);
	for(int i=0;i<N;i++)
		nod[i].pb(i);
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,k;
	scanf("%i %i",&n,&k);
	string s;
	cin >> s;
	for(int i=0;i<k;i++){
		int c;
		scanf("%i",&c);
		while(c--){
			int a;
			scanf("%i",&a);
			inds[a-1].pb(i);
		}
	}
	for(int i=0;i<n;i++){
		if(inds[i].size()==1){
			if(on[inds[i][0]]<0){
				cnt-=min(c1[find(inds[i][0])],c2[find(inds[i][0])]);
			}
			if(s[i]=='0'){
				if(on[inds[i][0]]<0)
					cnt++;
				on[inds[i][0]]=1;
			}
			else
				on[inds[i][0]]=0;
			dfs(inds[i][0]);
		}
		if(inds[i].size()==2){
			int a=inds[i][0],b=inds[i][1];
				graf[a].pb({b,s[i]=='0'});
				graf[b].pb({a,s[i]=='0'});
				if(on[a]>=0&&on[b]<0){
					cnt-=min(c1[find(b)],c2[find(b)]);
					dfs(a);
				}
				if(on[b]>=0&&on[a]<0){
					cnt-=min(c1[find(a)],c2[find(a)]);
					dfs(b);
				}
				if(on[a]<0&&on[b]<0)
					merge(a,b,s[i]!='0');
		}
		printf("%i\n",cnt);
	}
	return 0;
}