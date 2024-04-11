
// Problem : G. Columns Swaps
// Contest : Codeforces - Codeforces Round #656 (Div. 3)
// URL : http://codeforces.com/contest/1385/problem/G
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
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&p:x)rd(p);}
template<typename C,typename...T>void rd(C&a,T&...args){rd(a);rd(args...);}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;int i=0;bool neg=false;if(s[0]=='-')neg=true,i++;for(;i<s.size();i++)a=a*10+s[i]-'0';if(neg)a*=-1;return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

int main()
{
	for(int t=ri();t--;){
		int n=ri();
		vector<int> a(n),b(n);
		rd(a,b);
		vector<int> cnt(n);
		for(auto p:a)
			cnt[p-1]++;
		for(auto p:b)
			cnt[p-1]++;
		bool k=0;
		for(int i=0;i<n;i++){
			if(cnt[i]!=2){
				printf("-1\n");
				k=1;
				break;
			}
		}
		if(k)
			continue;
		vector<vector<int> > graf(n);
		map<int,int> ind[n];
		for(int i=0;i<n;i++)
			a[i]--,b[i]--,graf[a[i]].pb(b[i]),graf[b[i]].pb(a[i]),ind[a[i]][b[i]]=ind[b[i]][a[i]]=i;
		vector<int> c(n);
		for(auto p:a)
			c[p]++;
		vector<int> done(n),sol;
		for(int i=0;i<n;i++){
			if(done[i])
				continue;
			queue<int> q;
			q.push(i);
			done[i]=1;
			vector<int> cyc;
			while(q.size()){
				int tr=q.front();
				q.pop();
				cyc.pb(tr);
				for(auto p:graf[tr]){
					if(!done[p]){
						done[p]=1;
						q.push(p);
						break;
					}
				}
			}
			int m=cyc.size();
			vector<int> pos;
			for(int i=0;i<m;i++)
				if(c[cyc[i]]!=1)
					pos.pb(i);
			if(pos.size()&1){
				printf("-1\n");
				k=1;
				break;
			}
			m=pos.size();
			if(m==0)
				continue;
			vector<int> prvo,drugo;
			int ccc=0;
			for(int i=0;;i=(i+2)%m){
				if(i==0){
					if(ccc)
						break;
					ccc++;
				}
				for(int j=pos[i];j!=pos[(i+1)%m];j=(j+1)%cyc.size()){
					int a=cyc[j],b=cyc[(j+1)%cyc.size()];
					prvo.pb(ind[a][b]);
				}
			}
			ccc=0;
			for(int i=1;;i=(i+2)%m){
				if(i==1){
					if(ccc)
						break;
					ccc++;
				}
				for(int j=pos[i];j!=pos[(i+1)%m];j=(j+1)%cyc.size()){
					int a=cyc[j],b=cyc[(j+1)%cyc.size()];
					drugo.pb(ind[a][b]);
				}
			}
			if(prvo.size()<drugo.size()){
				for(auto p:prvo)
					sol.pb(p);
			}
			else{
				for(auto p:drugo)
					sol.pb(p);
			}
		}
		if(k)
			continue;
		printf("%i\n",sol.size());
		for(auto p:sol)
			printf("%i ",p+1);
		printf("\n");
	}
	return 0;
}