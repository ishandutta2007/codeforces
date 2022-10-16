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
int n,m;
vector<vector<int> > mat;
bool adj[16][16];
vector<vector<bool> > moze;
bool check_using_dp(){
        bool dp[n][1<<n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<(1<<n);j++)
                for(int k=0;k<n;k++)
                    dp[i][j][k]=false;
        }
        for(int i=0; i<n; i++)
            dp[i][1<<i][i]=true;
        for(int i=0; i<(1<<n); i++){
            for(int j=0; j<n; j++)
                if(i&(1<<j)){
                    for(int k=0; k<n; k++){
                        if((i&(1<<k)) && adj[k][j] && k!=j)
                        for(int l=0;l<n;l++)
                            if( (i&(1<<k)) && adj[k][j] && k!=j && dp[k][i^(1<<j)][l]){
                                dp[j][i][l]=true;
                            }
                    }
                }
        }
        for(int i=0; i<n; i++)
            for(int l=0;l<n;l++)
        {
            if(dp[i][(1<<n)-1][l])
            if(moze[l][i]||moze[i][l])
                return true;
        }
        return false;
    }
bool test(int k)
{
    //printf("Testiram %i\n",k);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j]=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            bool test=true;
            for(int l=0;l<m;l++)
            {
                int d=abs(mat[i][l]-mat[j][l]);
                if(d<k)
                {
                    test=false;
                    break;
                }
            }
            if(test)
            {
                //printf("%i %i\n",i,j);
                adj[i][j]=true;
                adj[j][i]=true;
            }
        }
    }
    for(int i=0;i<n;i++)
        fill(all(moze[i]),false);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            bool test=true;
            for(int l=0;l<m-1;l++)
            {
                if(abs(mat[j][l]-mat[i][l+1])<k){
                    test=false;
                    break;
                }
            }
            if(test)
                moze[i][j]=true;
            else
                moze[i][j]=false;
        }
    }
    return check_using_dp();
}
int main()
{
    scanf("%i %i",&n,&m);
    mat.resize(n,vector<int>(m));
    moze.resize(n,vector<bool>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%i",&mat[i][j]);
        }
    }
    int l=0,r=1e9;
    while(l<r)
    {
        int m=(l+r+1)>>1;
        if(test(m))
        {
            l=m;
        }
        else
        {
            r=m-1;
        }
    }
    printf("%i\n",l);
    return 0;
}