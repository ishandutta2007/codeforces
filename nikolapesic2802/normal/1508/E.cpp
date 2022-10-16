
// Problem: E. Tree Calendar
// Contest: Codeforces - Codeforces Round #715 (Div. 1)
// URL: https://codeforces.com/contest/1508/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
template<int D, typename T>struct vec : public vector<vec<D - 1, T>> {template<typename... Args>vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}};
template<typename T>struct vec<1, T> : public vector<T> {vec(int n = 0, T val = T()) : vector<T>(n, val) {}};
template<class T1,class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> istream& operator>>(istream& is,pair<T1,T2>& a) {is>>a.f>>a.s;return is;}
template<class T> istream& operator>>(istream& is,vector<T>& a) {for(auto &p:a)is>>p;return is;}
int ri(){int x;scanf("%i",&x);return x;}
void rd(int&x){scanf("%i",&x);}
void rd(long long&x){scanf("%lld",&x);}
void rd(double&x){scanf("%lf",&x);}
void rd(long double&x){scanf("%Lf",&x);}
void rd(string&x){cin>>x;}
void rd(char*x){scanf("%s",x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&p:x)rd(p);}
template<typename C,typename...T>void rd(C&a,T&...args){rd(a);rd(args...);}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;int i=0;bool neg=false;if(s[0]=='-')neg=true,i++;for(;i<s.size();i++)a=a*10+s[i]-'0';if(neg)a*=-1;return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

void no(){
	printf("NO\n");
	exit(0);
}
const int N=3e5+5,L=19;
vector<vector<int>> graf(N),sol(N);
int up[N][L],dep[N],a[N],deg[N],done[N],solA[N],added[N];
void init(int tr){
	for(auto p:graf[tr]){
		up[p][0]=tr;
		dep[p]=dep[tr]+1;
		init(p);
	}
}
int lca(int a,int b){
	if(dep[a]<dep[b])
		swap(a,b);
	for(int l=L-1;l>=0;l--)
		if(dep[a]-dep[b]>=(1<<l))
			a=up[a][l];
	if(a==b)
		return a;
	for(int l=L-1;l>=0;l--)
		if(up[a][l]!=up[b][l])
			a=up[a][l],b=up[b][l];
	return up[a][0];
}
int act=1,ind;
void validate(int tr){
	if(!done[tr]){
		if(a[tr]!=ind)
			no();
		ind++;
	}
	solA[tr]=act++;
	for(auto p:sol[tr])
		validate(p);
	vector<pair<int,int>> ostali;
	for(auto p:graf[tr])
		if(!added[p])
			ostali.pb({a[p],p});
	sort(all(ostali));
	for(auto p:ostali)
		validate(p.s);
}
int main()
{
	int n=ri();
	for(int i=0;i<n;i++)
		a[i]=ri(),a[i]--;
	deg[0]++;
	for(int i=1;i<n;i++){
		int u=ri(),v=ri();
		u--;v--;
		graf[u].pb(v);
		deg[u]++;
		deg[v]++;
	}
	init(0);
	for(int j=1;j<L;j++)
		for(int i=0;i<n;i++)
			up[i][j]=up[up[i][j-1]][j-1];
	vector<pair<int,int>> aa;
	for(int i=0;i<n;i++)
		aa.pb({a[i],i});
	sort(all(aa));
	ll cntDay=0;
	int last=0;
	int cntDel=0;
	for(auto trPair:aa){
		int i=trPair.s;
		if(deg[i]==1){
			if(lca(last,i)!=last)
				no();
			deg[i]--;
			cntDay+=dep[i];
			deg[up[i][0]]--;
			int tr=i;
			while(tr!=last){
				sol[up[tr][0]].pb(tr);
				added[tr]=1;
				tr=up[tr][0];
			}
			last=up[i][0];
			done[i]=1;
			cntDel++;
		}
		else{
			if(lca(last,i)!=last&&lca(last,i)!=i)
				no();
			if(lca(last,i)==last){
				int tr=i;
				while(tr!=last){
					sol[up[tr][0]].pb(tr);
					added[tr]=1;
					tr=up[tr][0];
				}
			}
			int tr=i;
			while(tr!=0){
				cntDay++;
				swap(a[tr],a[up[tr][0]]);
				tr=up[tr][0];
			}
			break;
		}
	}
	
	ind=cntDel;
	validate(0);
	
	printf("YES\n");
	printf("%lld\n",cntDay);
	for(int i=0;i<n;i++)
		printf("%i ",solA[i]);
	return 0;
}