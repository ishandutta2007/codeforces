
// Problem: D. Swap Pass
// Contest: Codeforces - Codeforces Round #715 (Div. 1)
// URL: https://codeforces.com/contest/1508/problem/D
// Memory Limit: 256 MB
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

const int N=2001;
vector<int> p(N);
int find(int tr){return tr==p[tr]?tr:p[tr]=find(p[tr]);}
void merge(int a,int b){p[find(a)]=find(b);}
const double Pi=acos(-1);
int main()
{ 
	//cout << atan2(2,2) << endl << atan2(2,-2) << endl << atan2(-2,-2) << endl << atan2(-2,2) << endl;
	iota(all(p),0);
	int n=ri();
	vector<pair<int,int>> pt(n);
	vector<int> val(n);
	for(int i=0;i<n;i++)
		rd(pt[i].f,pt[i].s,val[i]),val[i]--;
	int st=-1;
	for(int i=0;i<n;i++){
		if(val[i]!=i){
			st=i;
			break;
		}
	}
	if(st==-1){
		printf("0\n");
		return 0;
	}
	for(int i=st+1;i<n;i++)
		pt[i].f-=pt[st].f,pt[i].s-=pt[st].s;
	pt[st]={0,0};
	vector<pair<double,int>> ind;
	for(int i=st+1;i<n;i++)
		ind.pb({atan2(pt[i].s,pt[i].f),i});
	sort(all(ind));
	vector<int> done(n);
	for(int i=0;i<n;i++){
		if(done[i])
			continue;
		done[i]=1;
		int tr=val[i];
		while(tr!=i){
			merge(i,tr);
			done[tr]=1;
			tr=val[tr];
		}
	}
	vector<pair<int,int>> sol;
	for(int i=0;i<n-st-2;i++){
		if(ind[i+1].f-ind[i].f<Pi&&find(ind[i+1].s)!=find(ind[i].s)){
			sol.pb({ind[i+1].s,ind[i].s});
			swap(val[ind[i+1].s],val[ind[i].s]);
			merge(ind[i+1].s,ind[i].s);
		}
	}
	if(2*Pi+ind[0].f-ind[n-st-2].f<Pi&&find(ind[0].s)!=find(ind[n-st-2].s)){
		sol.pb({ind[0].s,ind[n-st-2].s});
		swap(val[ind[0].s],val[ind[n-st-2].s]);
		merge(ind[0].s,ind[n-st-2].s);
	}
	int cnt=0;
	while(val[st]!=st){
		sol.pb({st,val[st]});
		val[st]=val[val[st]];
		cnt++;
	}
	assert(cnt==n-st-1);
	printf("%i\n",sol.size());
	for(auto p:sol)
		printf("%i %i\n",p.f+1,p.s+1);
	return 0;
}