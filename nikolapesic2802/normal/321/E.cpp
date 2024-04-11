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
template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	os << '{';
	for(int i=0;i<sz(a);i++)
	{
		if(i>0&&i<sz(a)-1)
			os << ", ";
		os << a[i];
	}
	os << '}';
    return os;
}
const int N=4005,inf=INT_MAX/2;
int pre[N][N],dp[805][N];
int in()
{
    register int c=getchar();
    int num=0;
    while(c>='0'&&c<='9')
    {
        num*=10;
        num+=c-'0';
        c=getchar();
    }
    return num;
}
int get(int l,int r)
{
    return (pre[r][r]-pre[l][r]-pre[r][l]+pre[l][l])/2;
}
void calc(int d,int l,int r,int L,int R)
{
    if(l>r)
        return;
    int mid=(l+r)>>1;
    pair<int,int> sol=mp(inf,0);
    for(int i=L;i<=min(mid-1,R);i++)
    {
        sol=min(sol,mp(dp[d-1][i]+get(i,mid),i));
    }
    dp[d][mid]=sol.first;
    calc(d,l,mid-1,L,sol.second);
    calc(d,mid+1,r,sol.second,R);
}
int main()
{
    int n,k;
    n=in();
    k=in();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            pre[i][j]=in()+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
    for(int i=1;i<=n;i++)
        dp[0][i]=inf;
    for(int i=1;i<=k;i++)
        calc(i,1,n,0,n);
    printf("%i\n",dp[k][n]);
    return 0;
}