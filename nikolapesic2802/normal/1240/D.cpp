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
 
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=5e5+1;
int main()
{
    int t;
    scanf("%i",&t);
    while(t--)
    {
    	int n;
    	cin >> n;
    	vector<int> a(n+1);
    	for(int i=0;i<n;i++)
    		cin >> a[i];
    	vector<map<int,int> > nxt(n+1);
    	vector<int> num(n+1);
    	ll sol=0;
    	for(int i=n-1;i>=0;i--)
    	{
    		if(nxt[i+1][a[i]]==0)
    			nxt[i][a[i]]=i;
    		else
    		{
    			int sl=nxt[i+1][a[i]];
    			num[i]=1+num[sl+1];
    			swap(nxt[i],nxt[sl+1]);
    			nxt[i][a[i]]=i;
    		}
    		sol+=num[i];
    	}
    	cout << sol << endl;
    }
    return 0;
}