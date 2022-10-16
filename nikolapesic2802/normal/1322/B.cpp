//RIP RATING :'(



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

const int L=24,N=1<<L;
vector<int> cnt1(N),cnt2(N);
vector<int> rip[L][L];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	scanf("%i",&n);
	vector<int> a(n);
	vector<int> cnt(L);
	for(int i=0;i<n;i++)
		scanf("%i",&a[i]);
	for(int i=0;i<n;i++){
		for(int k=L-1;k>=0;k--){
			int trMask=0;
			for(int j=k;j>=0;j--){
				if(a[i]&(1<<j))
					trMask=trMask*2+1;
				else
					trMask=trMask*2;
				while(rip[k][j].size()<=trMask)
					rip[k][j].pb(0);
				rip[k][j][trMask]++;
			}
		}
	}
	vector<int> sol(L+1),solO(L+1);
	for(int i=0;i<n;i++)
		for(int j=0;j<L;j++)
			if(a[i]&(1<<j))
				sol[j]+=n-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<L;j++)
			if(a[i]&(1<<j))
				solO[j+1]--;
	}
	for(int i=0;i<n;i++){
		for(int k=L-1;k>=0;k--){
				int trMask=0;
				for(int j=k;j>=0;j--){
					if(a[i]&(1<<j)){
						if(rip[k][j].size()>trMask*2+1)
							solO[k+1]+=rip[k][j][trMask*2+1];
					}
					if(a[i]&(1<<j))
						trMask=trMask*2;
					else
						trMask=trMask*2+1;
				}
		}
	}
	//cout << sol << solO << endl;
	for(int i=0;i<=L;i++){
		assert(solO[i]%2==0);
		sol[i]=(sol[i]+solO[i]/2)&1;
	}
	int ans=0;
	for(int i=0;i<=L;i++)
		if(sol[i])
			ans+=1<<i;
	printf("%i\n",ans);
	return 0;
}