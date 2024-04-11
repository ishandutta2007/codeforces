
// Problem : E. Simple Skewness
// Contest : 8VC Venture Cup 2016 - Elimination Round
// URL : https://codeforces.com/contest/626/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define f first
#define s second
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

vector<ll> sum;
int n;
ld getSS(int i,int l){
	ld ss=sum[i];
	if(i-l)
		ss-=sum[i-l-1];
	ss+=sum[n-1]-sum[n-l-1];
	ss/=1+2*l;
	return ss;
}
int main()
{
	scanf("%i",&n);
	sum.resize(n);
	vector<int> x(n);
	for(int i=0;i<n;i++)
		scanf("%i",&x[i]);
	sort(all(x));
	for(int i=0;i<n;i++)
		sum[i]=x[i];
	for(int i=1;i<n;i++)
		sum[i]+=sum[i-1];
	ld sol=0;
	int gde=0,koliko=0;
	for(int i=1;i<n-1;i++){
		int l=1,r=min(i,n-i-1);
		while(l<r){
			int m=(l+r+1)>>1;
			if(getSS(i,m)>getSS(i,m-1))
				l=m;
			else
				r=m-1;
		}
		if(getSS(i,l)-x[i]>sol)
			sol=getSS(i,l)-x[i],gde=i,koliko=l;
	}
	vector<int> uzimam;
	for(int i=gde;i>=gde-koliko;i--)
		uzimam.pb(x[i]);
	for(int i=n-1;i>n-1-koliko;i--)
		uzimam.pb(x[i]);
	sort(all(uzimam));
	printf("%i\n",uzimam.size());
	for(auto p:uzimam)
		printf("%i ",p);
	return 0;
}