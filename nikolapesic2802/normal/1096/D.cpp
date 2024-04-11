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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
const int N=1e5+5;
int n;
vector<vector<int> > pos(4);
string lol="hard";
vector<int> a(N);
string s;
ll dp[N][4];
ll calc(int tr,int p)
{
    if(p==4)
        return LLONG_MAX/2;
    if(tr==n)
        return 0;
    if(dp[tr][p]!=-1)
        return dp[tr][p];
    if(s[tr]==lol[p])
    {
        dp[tr][p]=min(calc(tr+1,p)+a[tr],calc(tr+1,p+1));
    }
    else
    {
        dp[tr][p]=calc(tr+1,p);
    }
    return dp[tr][p];
}
int main()
{
    memset(dp,-1,sizeof(dp));
	scanf("%i",&n);
	cin >> s;
	for(int i=0;i<n;i++){
        scanf("%i",&a[i]);
	}
	printf("%lld\n",calc(0,0));
    return 0;
}