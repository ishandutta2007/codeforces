// Problem : G. Sum of Prefix Sums
// Contest : Educational Codeforces Round 82 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1303/problem/G
// Memory Limit : 512 MB
// Time Limit : 6000 ms
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

struct prava{
	ll k,n;
	ll get(ll x){
		return x*k+n;
	}
};
prava em={0,0};
const int N=150001;
int maxLen;
vector<prava> LiChao(4*N,em);
void add(prava p,int l=0,int r=maxLen,int i=1){
	int m=(l+r)>>1;
	bool le=LiChao[i].get(l)<p.get(l),mid=LiChao[i].get(m)<p.get(m);
	if(mid)
		swap(p,LiChao[i]);
	if(l==r)
		return;
	if(le!=mid)
		add(p,l,m,2*i);
	else
		add(p,m+1,r,2*i+1);
}
ll get(int pos,int l=0,int r=maxLen,int i=1){
	if(l==r)
		return LiChao[i].get(pos);
	int m=(l+r)>>1;
	if(pos<=m)
		return max(LiChao[i].get(pos),get(pos,l,m,2*i));
	return max(LiChao[i].get(pos),get(pos,m+1,r,2*i+1));
}
vector<vector<int> > graf(N);
vector<int> a(N),done(N),siz(N);
ll ans=0;
void init(int tr,int par){
	siz[tr]=1;
	for(auto p:graf[tr])
		if(p!=par&&!done[p])
			init(p,tr),siz[tr]+=siz[p];
}
int findCentroid(int tr,int par,int s){
	for(auto p:graf[tr])
		if(p!=par&&!done[p]&&siz[p]>s/2)
			return findCentroid(p,tr,s);
	return tr;
}
struct info{
	ll sum,up,down;
	int len;
};
info beg={0,0,0,0};
vector<info> nodes;
void dfs(int tr,int par,info trInf){
	trInf.len++;
	trInf.up+=(ll)a[tr]*trInf.len;
	trInf.down+=trInf.sum+a[tr];
	trInf.sum+=a[tr];
	maxLen=max(maxLen,trInf.len+1);
	nodes.pb(trInf);
	for(auto p:graf[tr])
		if(p!=par&&!done[p])
			dfs(p,tr,trInf);
}
void decomp(int tr){
	init(tr,tr);
	tr=findCentroid(tr,tr,siz[tr]);
	vector<vector<info> > sinovi;
	maxLen=0;
	for(auto p:graf[tr])
		if(!done[p])
			nodes.clear(),dfs(p,tr,beg),sinovi.pb(nodes);
	for(auto &p:sinovi)
		for(auto &d:p){
			d.len++;
			d.down+=(ll)a[tr]*d.len;
		}
	for(int i=0;i<maxLen*4;i++)
		LiChao[i]=em;
	for(auto p:sinovi){
		for(auto d:p)
			ans=max(ans,get(d.len)+d.down);
		for(auto d:p)
			add({d.sum,d.up});
	}
	for(int i=0;i<maxLen*4;i++)
		LiChao[i]=em;
	reverse(all(sinovi));
	for(auto p:sinovi){
		for(auto d:p)
			ans=max(ans,get(d.len)+d.down);
		for(auto d:p)
			add({d.sum,d.up});
	}
	for(auto p:sinovi)
	    for(auto d:p)
	        ans=max(ans,d.up+d.sum+a[tr]);
	done[tr]=1;
	for(auto p:graf[tr])
		if(!done[p])
			decomp(p);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	scanf("%i",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%i %i",&a,&b);
		a--;b--;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	for(int i=0;i<n;i++)
		scanf("%i",&a[i]);
	decomp(0);
	printf("%lld\n",ans);
	return 0;
}