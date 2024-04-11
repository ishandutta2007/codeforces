
// Problem : F. Make k Equal
// Contest : Codeforces Round #629 (Div. 3)
// URL : https://codeforces.com/contest/1328/problem/F
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
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double
#define li __int128

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
template<class T1, class T2> istream& operator>>(istream& is,pair<T1,T2>& a) {is>>a.f>>a.s;return is;}
template<class T> istream& operator>>(istream& is,vector<T>& a) {for(auto &p:a)is>>p;return is;}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;for(auto p:s)a=a*10+p-'0';return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

int main()
{
	int n,k;
	scanf("%i %i",&n,&k);
	map<int,int> mp;
	for(int i=0;i<n;i++){
		int a;
		scanf("%i",&a);
		mp[a]++;
	}
	
	vector<pair<int,int> > a;
	for(auto p:mp){
		a.pb(p);
		if(p.s>=k){
			printf("0\n");
			exit(0);
		}
	}
	n=a.size();
	vector<pair<int,ll> > up(n),down(n);
	up[0]={a[0].s,0};
	for(int i=1;i<n;i++){
		up[i]={up[i-1].f+a[i].s,up[i-1].s+(ll)up[i-1].f*(a[i].f-a[i-1].f)};
	}
	down[n-1]={a[n-1].s,0};
	for(int i=n-2;i>=0;i--){
		down[i]={down[i+1].f+a[i].s,down[i+1].s+(ll)down[i+1].f*(a[i+1].f-a[i].f)};
	}
	ll sol=LLONG_MAX;
	for(auto p:up)
		if(p.f>=k)
			sol=min(sol,p.s);
	for(auto p:down)
		if(p.f>=k)
			sol=min(sol,p.s);
	for(int i=0;i<n;i++){
		if(up[i].f>=k){
			if(i==0){
				printf("0\n");
				exit(0);
			}
			ll save=(ll)min(up[i-1].f,(up[i].f-k));
			sol=min(sol,up[i].s-save);
			break;
		}
	}
	for(int i=n-1;i>=0;i--){
		if(down[i].f>=k){
			if(i==n-1){
				printf("0\n");
				exit(0);
			}
			ll save=(ll)min(down[i+1].f,(down[i].f-k));
			sol=min(sol,down[i].s-save);
			break;
		}
	}
	for(int i=0;i<n-1;i++){
		if(up[i].f<k&&down[i+1].f<k){
			int ostalo=k-max(up[i].f,down[i+1].f);
			int mn=min(up[i].f,down[i+1].f);
			sol=min(sol,up[i].s+down[i+1].s+ostalo+(ll)mn*(a[i+1].f-a[i].f-1));
		}
	}
	printf("%lld\n",sol);
	return 0;
}