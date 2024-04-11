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

const int N=4000,L=70;
int dp[N][L][L][2];
int n;
vector<int> sums(N);
int get(int l,int r)
{
    int ans=sums[r];
    if(l)
        ans-=sums[l-1];
    return ans;
}
int calc(int l,int u1,int u2,int p)
{
    if(dp[l][u1][u2][p]!=-1)
        return dp[l][u1][u2][p];
    int k=u1+u2+1;
    if(p==0)
    {
        int r=l+u2;
        int le=l,ri=n-r-1,ostalo=ri-le+1;
        if(ostalo<k)
            return 0;
        dp[l][u1][u2][p]=get(le,le+k-1)+calc(l+k,u1,u2,1);
        if(ostalo>k)
            dp[l][u1][u2][p]=max(dp[l][u1][u2][p],get(le,le+k)+calc(l+k+1,u1+1,u2,1));
    }
    else
    {
        int r=l-u1-1;
        int le=l,ri=n-r-1,ostalo=ri-le+1;
        if(ostalo<k)
            return 0;
        dp[l][u1][u2][p]=calc(l,u1,u2,0)-get(ri-k+1,ri);
        if(ostalo>k)
            dp[l][u1][u2][p]=min(dp[l][u1][u2][p],calc(l,u1,u2+1,0)-get(ri-k,ri));
    }
    return dp[l][u1][u2][p];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%i",&n);
	for(int i=0;i<n;i++)
    {
        scanf("%i",&sums[i]);
        if(i)
            sums[i]+=sums[i-1];
    }
    printf("%i\n",calc(0,0,0,0));
    return 0;
}