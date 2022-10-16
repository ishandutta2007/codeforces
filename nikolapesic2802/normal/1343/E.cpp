
// Problem : E. Weights Distributing
// Contest : Codeforces - Codeforces Round #636 (Div. 3)
// URL : https://codeforces.com/contest/1343/problem/E
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double
#define li __int128

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<int D, typename T>struct vec : public vector<vec<D - 1, T>> {static_assert(D >= 1, "Vector dimension must be greater than zero!");template<typename... Args>vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}};
template<typename T>struct vec<1, T> : public vector<T> {vec(int n = 0, T val = T()) : vector<T>(n, val) {}};
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1, class T2> istream& operator>>(istream& is,pair<T1,T2>& a) {is>>a.f>>a.s;return is;}
template<class T> istream& operator>>(istream& is,vector<T>& a) {for(auto &p:a)is>>p;return is;}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;for(auto p:s)a=a*10+p-'0';return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

void test(){
	int n,m,a,b,c;
	scanf("%i %i %i %i %i",&n,&m,&a,&b,&c);
	a--;b--;c--;
	vector<ll> p(m);
	for(int i=0;i<m;i++)
		scanf("%lld",&p[i]);
	sort(all(p));
	for(int i=1;i<m;i++)
		p[i]+=p[i-1];
	vector<vector<int> > graf(n);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%i %i",&a,&b);
		a--;b--;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	
	if(a==b&&b==c){
		printf("0\n");
		return;
	}
	
	vector<int> distA(n,-1),distB(n,-1),distC(n,-1);
	queue<int> q;
	
	q.push(a);
	distA[a]=0;
	while(q.size()){
		int tr=q.front();
		q.pop();
		for(auto p:graf[tr]){
			if(distA[p]==-1){
				distA[p]=distA[tr]+1,q.push(p);
			}
		}
	}
	
	q.push(b);
	distB[b]=0;
	while(q.size()){
		int tr=q.front();
		q.pop();
		for(auto p:graf[tr]){
			if(distB[p]==-1){
				distB[p]=distB[tr]+1,q.push(p);
			}
		}
	}
	
	q.push(c);
	distC[c]=0;
	while(q.size()){
		int tr=q.front();
		q.pop();
		for(auto p:graf[tr]){
			if(distC[p]==-1){
				distC[p]=distC[tr]+1,q.push(p);
			}
		}
	}
	/*for(int i=0;i<n;i++){
		assert(distA[i]>=0&&distB[i]>=0&&distC[i]>=0);
	}*/
	ll sol=LLONG_MAX;
	for(int i=0;i<n;i++){
		if(distA[i]<0||distB[i]<0||distC[i]<0)
			continue;
		int cnt=distA[i]+distB[i]+distC[i];
		if(cnt<=m&&cnt>0){
			if(distB[i]==0)
				sol=min(sol,p[cnt-1]);
			else
				sol=min(sol,p[cnt-1]+p[distB[i]-1]);
		}
	}
	//assert(sol>=0);
	printf("%lld\n",sol);
}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--){
		test();
	}
	return 0;
}