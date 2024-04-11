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
const int N=5005;
int n;
int dp[N][N];
int nxt[N];
int calc(int pos,int cnt)
{
    //printf("%i %i\n",pos,cnt);
    if(cnt==-1)
        return INT_MIN/10;
    if(pos==n)
        return 0;
    if(dp[pos][cnt]!=-1)
        return dp[pos][cnt];
    dp[pos][cnt]=max(calc(pos+1,cnt),nxt[pos]-pos+calc(nxt[pos],cnt-1));
    return dp[pos][cnt];
}
int main()
{
    memset(dp,-1,sizeof(dp));
	int k;
	scanf("%i %i",&n,&k);
	vector<int> a(n);
	for(int i=0;i<n;i++)
        scanf("%i",&a[i]);
    sort(all(a));
    for(int i=0;i<n;i++)
    {
        int j;
        for(j=i;j<n;j++)
        {
            if(a[j]>a[i]+5)
                break;
        }
        nxt[i]=j;
    }
    printf("%i\n",calc(0,k));
    return 0;
}