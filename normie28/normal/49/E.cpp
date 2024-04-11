
// Problem : E. Common ancestor
// Contest : Codeforces - Codeforces Beta Round #46 (Div. 2)
// URL : https://codeforces.com/problemset/problem/49/E
// Memory Limit : 256 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define p1 first
#define p2 second.first
#define p3 second.second
#define F first
#define S second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
string s[2];
vector <string> p[200];
int dp[200][200],t[2][100][100][100],n;
int main()
{
	fio;
    cin >> s[0] >> s[1];
    cin >> n;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        p[s[0]-'a'].push_back(s.substr(3));
    }
    int l[2]={s[0].length(),s[1].length()};
    for (int zz=0;zz<2;zz++)
        for (int i=0;i<l[zz];i++)
            for (int j=0;j<l[zz]-i;j++)
                for (int k=0;k<26;k++)
                if (i==0) {
                    if (s[zz][j]-'a'==k){
                    t[zz][j][j+i][k]=1;
                    }
                } else
                for (auto x:p[k])
                for (int e=0;e<i;e++)
                if (t[zz][j][j+e][x[0]-'a']==1&&t[zz][j+e+1][j+i][x[1]-'a']==1) {
                    t[zz][j][j+i][k]=1;
                }
    for (int i=0;i<100;i++)
    for (int j=0;j<100;j++) dp[i][j]=100;
    for (int i=0;i<l[0];i++)
        for (int j=0;j<l[1];j++)
            for (int k1=0;k1<=i;k1++)
                for (int k2=0;k2<=j;k2++)
                    for (int f=0;f<26;f++){
                    if (t[0][0][i][f]&&t[1][0][j][f]) dp[i][j]=1;
                    if (t[0][k1+1][i][f]&&t[1][k2+1][j][f])
                    dp[i][j]=min(dp[i][j],dp[k1][k2]+1);
                    }
    int ans=dp[l[0]-1][l[1]-1];
    if (ans==100) cout << -1; else cout << ans;
}