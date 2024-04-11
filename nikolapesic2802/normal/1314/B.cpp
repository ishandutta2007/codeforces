
// Problem : B. Double Elimination
// Contest : Codeforces Round #623 (Div. 1, based on VK Cup 2019-2020 - Elimination Round, Engine)
// URL : https://codeforces.com/contest/1314/problem/B
// Memory Limit : 512 MB
// Time Limit : 2000 ms
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

const int oo=INT_MIN/3;
int total=0;
vector<bool> my;
void solve(vector<array<int,4> > pairs){
	/*printf("%i!: \n",pairs.size());
	for(auto p:pairs){
		for(int j=0;j<4;j++)
			printf("%i: %i    ",j,p[j]);
		printf("\n");
	}*/
	if(pairs.size()==1){
		printf("%i\n",max({pairs[0][0],pairs[0][1]+1,pairs[0][2]+1,pairs[0][3]+1}));
		exit(0);
	}
	vector<array<int,4> > novi;
	for(int i=0;i<pairs.size();i+=2){
		array<int,4> a=pairs[i],b=pairs[i+1];
		array<int,4> sol;
		sol[0]=max({oo,a[0]+b[0]});
		sol[1]=max({oo,a[1]+b[0]+1,b[1]+a[0]+1});
		sol[2]=max({oo,a[2]+b[2]+2,a[2]+b[0]+2,b[2]+a[0]+2,a[1]+b[0]+2,b[1]+a[0]+2});
		sol[3]=max({oo,a[1]+b[1]+2,a[1]+b[2]+3,a[2]+b[1]+3,a[3]+b[0]+3,b[3]+a[0]+3,a[3]+b[1]+3,a[3]+b[2]+3,a[3]+b[3]+3,b[3]+a[1]+3,b[3]+a[2]+3});
		novi.pb(sol);
	}
	solve(novi);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,k;
	scanf("%i %i",&n,&k);
	int m=1<<n;
	my.resize(m);
	for(int i=0;i<k;i++){
		int a;
		scanf("%i",&a);
		a--;
		my[a]=1;
	}
	vector<array<int,4> > pairs;
	for(int i=0;i<m;i+=2){
		if(my[i]+my[i+1]==2){
			pairs.pb({oo,oo,oo,1});
		}
		if(my[i]+my[i+1]==1){
			pairs.pb({oo,1,1,oo});
		}
		if(my[i]+my[i+1]==0){
			pairs.pb({0,oo,oo,oo});
		}
	}
	solve(pairs);
	printf("%i\n",total);
	return 0;
}