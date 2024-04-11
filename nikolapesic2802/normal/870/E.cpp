
// Problem : E. Points, Lines and Ready-made Titles
// Contest : Technocup 2018 - Elimination Round 2
// URL : https://codeforces.com/contest/870/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

const int N=1e5+5;
vector<int> par(N),cnt(N),siz(N,1);
vector<set<int> > coords(N);
map<int,int> ind;
int find(int tr){return tr==par[tr]?tr:par[tr]=find(par[tr]);}
void merge(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b)
		return;
	if(coords[a].size()>coords[b].size())
		swap(a,b);
	cnt[b]+=cnt[a];
	siz[b]+=siz[a];
	for(auto p:coords[a])
		coords[b].insert(p);
	par[a]=b;
}

const int mod=1e9+7; //998244353
int add(int a,int b){
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int sub(int a,int b){
    a-=b;
    if(a<0)
        a+=mod;
    return a;
}
int mul(int a,int b){
    return (long long)a*b%mod;
}
int pwrmod(int x,int k){
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
vector<int> fact(1,1),ifact(N),pwr(1,1);
int nCk(int n,int k){
	//printf("%i %i\n",n,k);
	return mul(fact[n],mul(ifact[k],ifact[n-k]));
}
int solve(int tot,int x,int y){
	int sol=0,sum=0;
	for(int i=0;i<=min(y,tot-x);i++)
		sum=add(sum,nCk(y,i));
	for(int i=x;i>=0;i--){
		sol=add(sol,mul(nCk(x,i),sum));
		if(tot-i+1<=y)
			sum=add(sum,nCk(y,tot-i+1));
	}
	return sol;
}
int main()
{
	for(int i=1;i<N;i++)
		pwr.pb(add(pwr.back(),pwr.back()));
	for(int i=1;i<N;i++)
		fact.pb(mul(fact.back(),i));
	ifact[N-1]=pwrmod(fact[N-1],mod-2);
	for(int i=N-2;i>=0;i--)
		ifact[i]=mul(ifact[i+1],i+1);
	iota(all(par),0);
	int n,a,b;
	scanf("%i",&n);
	map<int,vector<int> > y;
	for(int i=0;i<n;i++)
		scanf("%i %i",&a,&b),y[a].pb(b);
	n=y.size();
	vector<pair<int,vector<int> > > cor;
	for(auto p:y)
		cor.pb(p);
	for(int i=0;i<n;i++){
		cnt[i]=cor[i].s.size();
		vector<int> mer;
		for(auto p:cor[i].s){
			coords[i].insert(p);
			if(ind.find(p)!=ind.end())
				mer.pb(ind[p]);
			else
				ind[p]=i;
		}
		for(auto p:mer)
			merge(i,p);
	}
	set<int> vals;
	for(int i=0;i<n;i++)
		vals.insert(find(i));
	vector<int> kk;
	for(auto p:vals)
		kk.pb(p);
	n=kk.size();
	for(int i=0;i<n;i++){
		swap(cnt[i],cnt[kk[i]]);
		swap(coords[i],coords[kk[i]]);
		swap(siz[i],siz[kk[i]]);
	}
	int sol=1;
	for(int i=0;i<n;i++){
		sol=mul(sol,solve(cnt[i],coords[i].size(),siz[i]));
	}
	printf("%i\n",sol);
	return 0;
}