
// Problem : D. Shortest and Longest LIS
// Contest : Codeforces Round #620 (Div. 2)
// URL : http://codeforces.com/contest/1304/problem/D
// Memory Limit : 256 MB
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

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int q;
	scanf("%i",&q);
	while(q--){
		int n;
		scanf("%i",&n);
		string s;
		cin >> s;
		int tr=0;
		vector<pair<int,int> > seq;
		for(auto p:s){
			if(seq.empty()||seq.back().f!=(p=='<'))
				seq.pb({p=='<',1});
			else
				seq.back().s++;
		}
		deque<int> mn,mx;
		int lst;
		if(seq.back().f==1)
			lst=seq.back().s+1;
		else
			lst=1;
		mn.pb(lst);
		reverse(all(seq));
		for(int i=0;i<seq.size();i++){
			auto p=seq[i];
			if(p.f==1){
				for(int i=lst-1;i>=lst-p.s;i--)
					mn.push_front(i);
				lst=lst;
			}
			else{
				if(i==seq.size()-1){
					for(int i=lst+1;i<=lst+p.s;i++)
						mn.push_front(i);
				}
				else{
					for(int i=lst+1;i<=lst+p.s-1;i++)
						mn.push_front(i);
					int mesta=seq[i+1].s;
					mn.push_front(lst+p.s+mesta);
					lst=lst+p.s+mesta;
				}
			}
		}
		for(auto p:mn)
			printf("%i ",p);
		printf("\n");
		
		if(seq[0].f==0)
			lst=n-seq[0].s;
		else
			lst=n;
		mx.pb(lst);
		for(int i=0;i<seq.size();i++){
			auto p=seq[i];
			if(p.f==0){
				for(int i=lst+1;i<=lst+p.s;i++)
					mx.push_front(i);
				lst=lst;
			}
			else{
				if(i==seq.size()-1){
					for(int i=lst-1;i>=lst-p.s;i--)
						mx.push_front(i);
				}
				else{
					for(int i=lst-1;i>=lst-p.s+1;i--)
						mx.push_front(i);
					int mesta=seq[i+1].s;
					mx.push_front(lst-p.s-mesta);
					lst=lst-p.s-mesta;
				}
			}
		}
		for(auto p:mx)
			printf("%i ",p);
		printf("\n");
	}
	return 0;
}