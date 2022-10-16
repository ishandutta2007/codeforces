// Problem : D. Coffee Varieties (hard version)
// Contest : Codeforces Round #616 (Div. 1)
// URL : https://codeforces.com/contest/1290/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

int n,k,u[1024];
bool ask(int i){
	printf("? %i\n",i+1);
	fflush(stdout);
	char c;
	scanf(" %c",&c);
	return c=='Y';
}
void reset(){
	printf("R\n");
	fflush(stdout);
}
void ans(){
	int cnt=0;
	for(int i=0;i<n;i++)
		cnt+=!u[i];
	printf("! %i\n",cnt);
	exit(0);
}
int main()
{
	scanf("%i %i",&n,&k);
	int b=n/k;
	if(b==1){
		for(int i=0;i<n;i++)
			u[i]=ask(i);
		ans();
	}
	vector<vector<int> > a;
	for(int i=0;i<b/2;i++){
		vector<int> t(1,i);
		for(int j=1;j<b/2;j++)
			t.pb((i+j)%b),t.pb((i-j+b)%b);
		t.pb(i+b/2);
		a.pb(t);
	}
	for(auto p:a){
		for(auto d:p)
			for(int i=0;i<k;i++)
				if(!u[i+d*k])
					u[i+d*k]=ask(i+d*k);
        reset();
	}
	for(auto p:a){
		for(auto d:p)
			for(int i=k-1;i>=0;i--)
				if(!u[i+d*k])
					u[i+d*k]=ask(i+d*k);
        reset();
	}
	ans();
	return 0;
}