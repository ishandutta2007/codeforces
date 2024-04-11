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

const int m=20,M=1<<m;
int dp[M];
int cnt[m][m];
int sum[M];
int e,mm;
int calc(int mask)
{
    if(mask==e)
        return 0;
    if(dp[mask]!=-1)
        return dp[mask];
    dp[mask]=INT_MAX/m;
    for(int i=0;i<mm;i++)
        if((mask&(1<<i))==0)
            dp[mask]=min(dp[mask],sum[mask]+calc(mask^(1<<i)));
    return dp[mask];
}
int main()
{
    for(int i=0;i<M;i++)
        dp[i]=-1;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	scanf("%i %i",&n,&mm);
	e=1<<mm;
	e--;
	string s;
	cin >>s;
	for(int i=1;i<n;i++)
        cnt[s[i-1]-'a'][s[i]-'a']++,cnt[s[i]-'a'][s[i-1]-'a']++;
    for(int i=0;i<M;i++)
        for(int j=0;j<mm;j++)
            if((i&(1<<j))!=0)
                for(int k=0;k<mm;k++)
                    if((i&(1<<k))==0)
                        sum[i]+=cnt[j][k];
    printf("%i\n",calc(0));
    return 0;
}