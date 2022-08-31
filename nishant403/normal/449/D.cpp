#include <bits/stdc++.h>
using namespace std;
  
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MOD = 1e9+7;
const int BT = 20;
const int N = (1<<BT);
const int MSK = (1<<BT) - 1;

int a[N],pw[N],n,x;

signed main()
{
    fast;
    
    pw[0] = 1;
    for(int i=1;i<N;i++) pw[i] = (pw[i-1] + pw[i-1])%MOD;
    for(int i=0;i<N;i++) pw[i]--;
    
    cin >> n;
    
    f(i,n)
    {
        cin >> x;
        a[x^MSK]++;
    }
    
    f(i,BT) f(j,N)
        if(j & (1<<i)) a[j]+=a[j^(1<<i)];
    
    int res = 0;
    
    for(int i=N-1;i>=0;i--)
    {
        int num = pw[a[i]];
        if(__builtin_popcount(i^MSK) & 1) num = (MOD - num)%MOD;
        res = (res + num)%MOD;
    }
    
    cout << res;
}