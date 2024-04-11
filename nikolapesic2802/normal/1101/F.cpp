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

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=400;
int dp[N][N][N];
int dist[N];
int get(int l,int r)
{
    return dist[r]-dist[l];
}
set<pair<int,int> > gradovi;
int calc(int l,int r,int R)
{
    if(l==r)
        return 0;
    if(R<0)
        return INT_MAX;
    if(dp[l][r][R]!=-1)
        return dp[l][r][R];
    dp[l][r][R]=INT_MAX;
    int d=get(l,r);
    int tr=d/(R+1);
    tr+=dist[l];
    int i=lower_bound(dist+l,dist+r+1,tr)-dist;
    if(i!=l)dp[l][r][R]=min(dp[l][r][R],max(calc(i-1,r,R-1),get(l,i-1)));
    dp[l][r][R]=min(dp[l][r][R],max(calc(i,r,R-1),get(l,i)));
    if(i!=r)dp[l][r][R]=min(dp[l][r][R],max(calc(i+1,r,R-1),get(l,i+1)));
    return dp[l][r][R];
}
int main()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++)
                dp[i][j][k]=-1;
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=0;i<n;i++)
        scanf("%i",&dist[i]);
    ll V=0;
    for(int i=0;i<m;i++)
    {
        vector<int> t(4);
        scanf("%i %i %i %i",&t[0],&t[1],&t[2],&t[3]);
        t[0]--;
        t[1]--;
        int a=calc(t[0],t[1],t[3]);
        ll d=(ll)a*t[2];
        V=max(V,d);
    }
    printf("%lld\n",V);
    return 0;
}