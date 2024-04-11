
// Problem : E. Anton and Ira
// Contest : Codeforces Round #324 (Div. 2)
// URL : https://codeforces.com/contest/584/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

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

const int N=2001;
int n,a;
vector<int> mapa(N),perm(N),done(N),cc;
void dfs(int tr){
	done[tr]=1;
	cc.pb(tr);
	if(!done[perm[tr]])
		dfs(perm[tr]);
}
vector<pair<int,int> > ins;
void solve(vector<int> cyc){
	//cout << cyc << endl;
	int n=cyc.size();
	if(n==1)
		return;
	if(n==2){
		ins.pb({cyc[0],cyc[1]});
		return;
	}
	for(int i=0;i<n;i++){
		int a=cyc[i],b=cyc[(i+1)%n],c=cyc[(i+2)%n];
		if((a<c&&a>b)||(a<b&&a>c)){
			ins.pb({a,b});
			vector<int> novi;
			for(int i=0;i<n;i++)
				if(cyc[i]!=b)
					novi.pb(cyc[i]);
			solve(novi);
			return;
		}
	}
	for(int i=0;i<n;i++){
		int a=cyc[i],b=cyc[(i+1)%n],c=cyc[(i+2)%n];
		if(a>b)
			continue;
		if((c>a&&c<b)||(c>b&&c<a)){
			set<int> drugi;
			drugi.insert(b);
			int tr=(i+2)%n;
			int lst=cyc[tr];
			while(cyc[tr]>a){
				drugi.insert(cyc[tr]);
				lst=cyc[tr];
				tr=(tr+1)%n;
			}
			if(cyc[tr]==a||lst>b)
				continue;
			//printf("%i %i %i\n",a,b,c);
			//cout << drugi << endl;
			tr=(tr-1+n)%n;
			ins.pb({a,cyc[tr]});
			vector<int> prvi,dr;
			for(int i=0;i<n;i++)
				if(drugi.count(cyc[i]))
					dr.pb(cyc[i]);
				else
					prvi.pb(cyc[i]);
			solve(prvi);
			solve(dr);
			return;
		}
	}
	assert(0);
}
int main()
{
	scanf("%i",&n);
	for(int i=0;i<n;i++)
		scanf("%i",&a),mapa[a]=i;
	ll treba=0;
	for(int i=0;i<n;i++)
		scanf("%i",&perm[i]),perm[i]=mapa[perm[i]],treba+=abs(perm[i]-i);
	for(int i=0;i<n;i++){
		if(done[i])
			continue;
		dfs(i);
		solve(cc);
		cc.clear();
	}
	reverse(all(ins));
	ll s=0;
	for(auto p:ins)
		s+=abs(p.f-p.s);
	assert(s==treba/2);
	printf("%lld\n%i\n",s,ins.size());
	for(auto p:ins)
		printf("%i %i\n",p.f+1,p.s+1);
	return 0;
}