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
vector<int> arr;
int n;
const int N=5000;
int dp[N][N][2];
int calc(int l,int r,int i)
{
    if(l==0&&r==n-1)
        return 0;
    if(dp[l][r][i]!=-1)
        return dp[l][r][i];
    int curr=0;
    if(i==0)
        curr=arr[l];
    else
        curr=arr[r];
    dp[l][r][i]=INT_MAX;
    if(l!=0)
        if(curr==arr[l-1])
            dp[l][r][i]=min(dp[l][r][i],calc(l-1,r,0));
        else
            dp[l][r][i]=min(dp[l][r][i],1+calc(l-1,r,0));
    if(r!=n-1)
        if(curr==arr[r+1])
            dp[l][r][i]=min(dp[l][r][i],calc(l,r+1,1));
        else
            dp[l][r][i]=min(dp[l][r][i],1+calc(l,r+1,1));
    return dp[l][r][i];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%i",&n);

    int last=-1;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        if(a!=last)
            arr.pb(a);
        last=a;
    }
    n=arr.size();
    int sol=INT_MAX;
    for(int i=0;i<n;i++)
        sol=min(sol,calc(i,i,0));
    printf("%i\n",sol);
    return 0;
}