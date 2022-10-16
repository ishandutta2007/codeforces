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

const int N=2001;
int dp[N][N][2];
vector<int> arr(N);
int calc(int l,int r,int i)
{
    if(l>r)
        return 0;
    if(dp[l][r][i]!=-1)
        return dp[l][r][i];
    dp[l][r][i]=calc(l+1,r,i);
    if(arr[l]==1)
    {
        if(i==0)
            dp[l][r][i]=max(dp[l][r][i],1+calc(l+1,r,0));
    }
    else
    {
        dp[l][r][i]=max(dp[l][r][i],1+calc(l+1,r,1));
    }
    return dp[l][r][i];
}
int main()
{
    memset(dp,-1,sizeof(dp));
	int n;
	scanf("%i",&n);
	arr.resize(n);
	for(int i=0;i<n;i++)
        scanf("%i",&arr[i]);
    reverse(all(arr));
    int sol=0;
    int lft=0;
    for(int i=0;i<n;i++)
    {
        int drugi=0;
        for(int j=n-1;j>=i;j--)
        {
            sol=max(sol,calc(i,j,0)+lft+drugi);
            if(arr[j]==1)
                drugi++;
        }
        if(arr[i]==2)
            lft++;
    }
    printf("%i\n",sol);
    return 0;
}