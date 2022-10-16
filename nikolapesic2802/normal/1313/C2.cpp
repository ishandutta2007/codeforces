
// Problem : C2. Skyscrapers (hard version)
// Contest : Codeforces Round #622 (Div. 2)
// URL : https://codeforces.com/contest/1313/problem/C2
// Memory Limit : 512 MB
// Time Limit : 3000 ms
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

const int N=5e5+5,L=20;
int mn[N][L];
vector<int> lg(N);
int get(int l,int r){
	int d=r-l+1;
	/*printf("%i %i:\n",l,r);
	printf("%i %i    %i %i\n",l,lg[d], r-(1<<lg[d])+1,lg[d]);*/
	return min(mn[l][lg[d]],mn[r-(1<<lg[d])+1][lg[d]]);
}
int main()
{
	lg[0]=-1;
	for(int i=1;i<N;i++)
		lg[i]=lg[i/2]+1;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	scanf("%i",&n);
	vector<int> m(n);
	for(int i=0;i<n;i++)
		scanf("%i",&m[i]),mn[i][0]=m[i];
	for(int j=1;j<L;j++)
		for(int i=0;i<N;i++)
			mn[i][j]=min(mn[i][j-1],mn[min(N-1,i+(1<<(j-1)))][j-1]);
	//printf("%i    %i\n",get(1,2),get(0,2));
	vector<ll> ri(n),le(n);
	le[0]=m[0];
	for(int i=1;i<n;i++){
		int l=0,r=i-1;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(get(mid,i-1)<=m[i])
				l=mid;
			else
				r=mid-1;
		}
		if(get(l,i-1)>m[i])
			le[i]=(ll)i*m[i]+m[i];
		else
			le[i]=(ll)(i-l)*m[i]+le[l];
	}
	ri[n-1]=m[n-1];
	for(int i=n-2;i>=0;i--){
		int l=i+1,r=n-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(get(i+1,mid)<=m[i])
				r=mid;
			else
				l=mid+1;
		}
		if(get(i+1,l)>m[i])
			ri[i]=(ll)(n-i)*m[i];
		else
			ri[i]=(ll)(l-i)*m[i]+ri[l];
	}
	ll sol=ri[0],gde=0;
	if(le[n-1]>sol)
		sol=le[n-1],gde=n-1;
	for(int i=1;i<n-1;i++){
		ll myAns=-m[i];
		int l=0,r=i-1;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(get(mid,i-1)<=m[i])
				l=mid;
			else
				r=mid-1;
		}
		if(get(l,i-1)>m[i])
			myAns+=(ll)i*m[i]+m[i];
		else
			myAns+=(ll)(i-l)*m[i]+le[l];
		l=i+1,r=n-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(get(i+1,mid)<=m[i])
				r=mid;
			else
				l=mid+1;
		}
		if(get(i+1,l)>m[i])
			myAns+=(ll)(n-i)*m[i];
		else
			myAns+=(ll)(l-i)*m[i]+ri[l];
		if(sol<myAns)
			sol=myAns,gde=i;
	}
	//printf("%lld %i\n",sol,gde);
	vector<int> ans(n);
	ans[gde]=m[gde];
	int tr=m[gde];
	for(int i=gde+1;i<n;i++){
		tr=min(tr,m[i]);
		ans[i]=tr;
	}
	tr=m[gde];
	for(int i=gde-1;i>=0;i--){
		tr=min(tr,m[i]);
		ans[i]=tr;
	}
	for(int i=0;i<n;i++)
		printf("%i ",ans[i]);
	return 0;
}