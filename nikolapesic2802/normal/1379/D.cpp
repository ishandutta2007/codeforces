
// Problem : D. New Passenger Trams
// Contest : Codeforces - Codeforces Round #657 (Div. 2)
// URL : https://codeforces.com/contest/1379/problem/D
// Memory Limit : 512 MB
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
void rd(string&x){cin>>x;}
void rd(char*x){scanf("%s",x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&p:x)rd(p);}
template<typename C,typename...T>void rd(C&a,T&...args){rd(a);rd(args...);}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;int i=0;bool neg=false;if(s[0]=='-')neg=true,i++;for(;i<s.size();i++)a=a*10+s[i]-'0';if(neg)a*=-1;return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

int n,h,m,k;
int gde;
vector<int> a,b;
void doit(){
	set<int> canceled;
	vector<pair<int,int> > events;
	int x=m/2;
	for(int i=0;i<n;i++){
		int dist;
		if(b[i]<x)
			dist=x-b[i];
		else
			dist=m-b[i];
		if(dist<k)
			events.pb({k-dist,i+1}),canceled.insert(i+1);
		if(b[i]<x)
			dist=b[i];
		else
			dist=b[i]-x;
		events.pb({dist+1,-i-1});
		if(dist+k<x)
			events.pb({dist+k,i+1});
	}
	sort(all(events));
	//cout << canceled << events << endl;
	gde=0;
	int sol=canceled.size();
	for(int t=0;t<events.size();){
		int tr=events[t].f;
		while(events[t].f==tr){
			if(events[t].s<0)
				canceled.insert(-events[t].s);
			else
				canceled.erase(events[t].s);
			t++;
		}
		if(canceled.size()<sol)
			sol=canceled.size(),gde=tr;
	}
}
void fuckingPrintTrainsWhy(){
	set<int> canceled;
	vector<pair<int,int> > events;
	int x=m/2;
	for(int i=0;i<n;i++){
		int dist;
		if(b[i]<x)
			dist=x-b[i];
		else
			dist=m-b[i];
		if(dist<k)
			events.pb({k-dist,i+1}),canceled.insert(i+1);
		if(b[i]<x)
			dist=b[i];
		else
			dist=b[i]-x;
		events.pb({dist+1,-i-1});
		if(dist+k<x)
			events.pb({dist+k,i+1});
	}
	sort(all(events));
	int sol=canceled.size();
	if(gde==0){
		printf("%i %i\n",canceled.size(),gde);
		for(auto p:canceled)
			printf("%i ",p);
		printf("\n");
	}
	for(int t=0;t<events.size();){
		int tr=events[t].f;
		while(events[t].f==tr){
			if(events[t].s<0)
				canceled.insert(-events[t].s);
			else
				canceled.erase(events[t].s);
			t++;
		}
		if(tr==gde){
			printf("%i %i\n",canceled.size(),gde);
			for(auto p:canceled)
				printf("%i ",p);
			printf("\n");
		}
	}
}
int main()
{
	rd(n,h,m,k);
	a.resize(n);
	b.resize(n);
	for(int i=0;i<n;i++)
		rd(a[i],b[i]);
	doit();
	fuckingPrintTrainsWhy();
	return 0;
}