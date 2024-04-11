
// Problem : D. Carousel
// Contest : Codeforces Round #629 (Div. 3)
// URL : https://codeforces.com/contest/1328/problem/D
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
	int t;
	scanf("%i",&t);
	while(t--){
		int n;
		scanf("%i",&n);
		vector<int> t(n);
		cin >> t;
		bool isti=1;
		for(int i=1;i<n;i++)
			if(t[i]!=t[0])
				isti=0;
		if(isti){
			printf("1\n");
			for(int i=0;i<n;i++)
				printf("1 ");
			printf("\n");
			continue;
		}
		if(n%2==0){
			printf("2\n");
			for(int i=0;i<n;i++)
				printf("%i ",1+(i&1));
			printf("\n");
			continue;
		}
		bool nasao=0;
		for(int i=0;i<n;i++){
			if(t[i]==t[(i+1)%n]){
				vector<int> ans(n);
				for(int j=i;j>=0;j--){
					ans[j]=1+((i-j)&1);
				}
				for(int j=i+1;j<n;j++){
					ans[j]=1+((j-i-1)&1);
				}
				printf("2\n");
				for(int i=0;i<n;i++)
					printf("%i ",ans[i]);
				printf("\n");
				nasao=1;
				break;
			}
		}
		if(nasao)
			continue;
		vector<int> ans(n);
		for(int i=0;i<n;i++){
			ans[i]=1+(i&1);
		}
		ans[n-1]=3;
		printf("3\n");
		for(int i=0;i<n;i++)
			printf("%i ",ans[i]);
		printf("\n");
	}
	return 0;
}