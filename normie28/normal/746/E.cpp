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
#define MOD (ll(100003))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
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
const int N = 2e5 + 7;
int n, m, T[N], p[2], ne[2], res;
bool taken[N];
map <int, int> M;
 
int main()
{
    fio;
    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>T[i];
        M[T[i]]++;
        p[(T[i] & 1)]++;
    }
    ne[0] = 2; ne[1] = 1;
    bool check = true;
    for(int i = 0; i < n; i++)
    {
        if(M[T[i]] > 1)
        {
            int x = (T[i] & 1);
            if(p[x] > p[x ^ 1]){
                x ^= 1;
                p[x]++; p[x ^ 1]--;
            }
            while(ne[x] <= m && M.count(ne[x]) > 0)
                ne[x] += 2;
            if(ne[x] > m) check = false;
            M[T[i]]--;
            T[i] = ne[x]; ne[x] += 2;
            taken[i] = true; res++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        int x = (T[i] & 1);
        if(!taken[i] && p[x] > n / 2)
        {
            x ^= 1;
            while(ne[x] <= m && M.count(ne[x]) > 0)
                ne[x] += 2;
            if(ne[x] > m) check = false;
            p[x]++; p[x ^ 1]--;
            T[i] = ne[x]; res++; ne[x] += 2;
        }
    }
    if(p[0] == p[1] && check){
        cout<<res<<endl;
        for(int i = 0; i < n; i++)
        cout<<T[i]<<' ';
    }
    else
    cout<<-1;
    cout<<endl;
}