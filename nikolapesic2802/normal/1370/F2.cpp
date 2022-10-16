
// Problem : F2. The Hidden Pair (Hard Version)
// Contest : Codeforces - Codeforces Round #651 (Div. 2)
// URL : https://codeforces.com/contest/1370/problem/F2
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

int cnt=0;
pair<int,int> ask(vector<int> sta){
	cnt++;
	if(cnt>11){
		while(true);
	}
	printf("? %i ",sta.size());
	for(auto p:sta)
		printf("%i ",p+1);
	printf("\n");
	fflush(stdout);
	int a,b;
	scanf("%i %i",&a,&b);
	return {a,b};
}
const int N=1001;
vector<vector<int> > graf(N);
int n;
vector<bool> taken(N);
int le,ri;
void mark(int st){
	vector<int> par(n,-1);
	int gde=-1;
	queue<int> q;
	q.push(st);
	par[st]=st;
	while(q.size()){
		int tr=q.front();
		q.pop();
		if(taken[tr]==1){
			gde=tr;
			break;
		}
		for(auto p:graf[tr]){
			if(par[p]==-1)
				par[p]=tr,q.push(p);	
		}
	}
	if(gde==le){
		le=st;
	}
	else{
		assert(gde==ri);
		ri=st;
	}
	assert(gde!=-1);
	while(par[gde]!=gde){
		gde=par[gde];
		taken[gde]=1;
	}
}
void test(){
	cnt=0;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
		graf[i].clear(),taken[i]=0;
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%i %i",&a,&b);
		a--;b--;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	vector<int> svi(n);
	iota(all(svi),0);
	int v,d;
	tie(v,d)=ask(svi);
	v--;
	taken[v]=1;
	le=ri=v;
	while(d>0){
		int k=(d+1)/2;
		vector<int> dist(n,-1);
		dist[le]=dist[ri]=0;
		queue<int> q;
		q.push(le);
		q.push(ri);
		vector<int> kandidati;
		while(q.size()){
			int tr=q.front();
			q.pop();
			if(dist[tr]==k)
				kandidati.pb(tr);
			for(auto p:graf[tr]){
				if(!taken[p]&&dist[p]==-1){
					dist[p]=dist[tr]+1;
					q.push(p);
				}
			}
		}
		assert(kandidati.size());
		int koji,kk;
		if(kandidati.size()==1){
			koji=kandidati[0];
		}
		else{
			tie(koji,kk)=ask(kandidati);
			koji--;
		}
		mark(koji);
		d-=k;
	}
	printf("! %i %i\n",le+1,ri+1);
	fflush(stdout);
	string s;
	cin >> s;
	assert(s[0]=='C');
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