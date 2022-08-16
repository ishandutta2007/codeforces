#include <bits/stdc++.h>
using namespace std;
 
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int MOD = 2520;

int pw[20];

int dp[20][2520][48][2];

vector<int> dd;

int val_mask[48];
int new_mask[48][10];

int go(int dg,int val,int mask,int less)
{   
    if(dg == -1) return (val % val_mask[mask] == 0);
    
    int & res = dp[dg][val][mask][less];
    
    if(res != -1) return res;
    
    res = 0;
    
    int l = 0;
    int r = dd[dg];
    
    if(less == 1) r = 9;
    
    for(int i=l;i<=r;i++)
    {
        res += go(dg-1,(val + (pw[dg]*i)) % MOD,new_mask[mask][i],less | (i<r));
    }
    
    return res;
}

int solve(int x)
{
    dd.clear();
    memset(dp,-1,sizeof(dp));
    
    while(x > 0)
    {
        dd.pb(x % 10);
        x /= 10;
    }
    
    return go((int)dd.size()-1,0,0,0);
}

void solve()
{
   int l,r;
   cin >> l >> r;
   cout << solve(r) - solve(l-1) << '\n';
}

signed main()
{
    pw[0] = 1;
    for(int i=1;i<20;i++) pw[i] = (pw[i-1]*10) % (2520);
    
    f(i,4) f(j,3) f(k,2) f(l,2)
    {
        int vv = 1;
        
        vv*= pow(2,i);
        vv*= pow(3,j);
        vv*= pow(5,k);
        vv*= pow(7,l);
        
        int msk = (i*12) + (j*4) + (k*2) + l;
        
        val_mask[msk] = vv;
        
        f(z,10)
        {
            int update = msk;
            
            if(z == 9)
            {
                update += (2-j)*4;
            }
            else if(z == 8)
            {
                update += (3-i)*12;
            }
            else if(z == 7)
            {
                update+=(1-l);
            }
            else if(z == 6)
            {
                if(i == 0) update += 12;
                if(j == 0) update += 4;
            }
            else if(z == 5)
            {
                update += (1-k)*2;
            }
            else if(z == 4)
            {
                if(i < 2) update += (2-i)*12;
            }
            else if(z == 3)
            {
                if(j < 1) update += (1-j)*4;
            }
            else if(z == 2)
            {
                if(i == 0) update += 12;
            }
           
            
            new_mask[msk][z] = update;
        }
    }
    
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}