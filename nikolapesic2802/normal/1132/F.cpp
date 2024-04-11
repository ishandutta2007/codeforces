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

string s;
const int N=505;
int dp[N][N][27];
int calc(int l,int r,int last)
{
    if(r<l)
        return 0;
    if(dp[l][r][last]!=-1)
        return dp[l][r][last];
    dp[l][r][last]=r-l+1;
    for(int i=l;i<=r;i++)
    {
        if(s[i]==last+'a')
        {
            dp[l][r][last]=min(dp[l][r][last],calc(l,i-1,last)+calc(i+1,r,last));
        }
        else
        {
            dp[l][r][last]=min(dp[l][r][last],1+calc(l,i-1,last)+calc(i+1,r,s[i]-'a'));
        }
    }
    return dp[l][r][last];
}
int main()
{
	int n;
	scanf("%i",&n);
	memset(dp,-1,sizeof(dp));
	cin >> s;
    printf("%i\n",calc(0,n-1,26));
    return 0;
}