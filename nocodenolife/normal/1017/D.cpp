#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,q;
    cin>>n>>m>>q;
    int maxx = pow(2,n) -1;
    int nums[maxx+1] = {0};
    int powe[14] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};
    int values[n];
    int added[maxx+1];
    ForA1(n)
    {
        cin>>values[i];
    }

    ForA1(maxx+1)
    {
        int value =0;
        int num = i;
        for(int j=0;j<n;j++)
        {
            int mo = num%2;
            value+= mo*values[j];
            num/=2; 
        }
        added[i] = value;
    }

    ForA1(m)
    {
        string x;
        cin>>x;
        int value =0;
        for(int j=0;j<x.size();j++)
        {
            if(x[j]=='1')
            {
                value+= powe[j];
            }
        }
        nums[value]++;
    }

    ll dp[maxx+1][101] = {{0}};
    ForA3(maxx+1)
    {
        int value = k;
        for(int i=0;i <= maxx;i++)
        {
            if(nums[i]==0)
                continue;
            int xored = value^i;
            xored = maxx - xored;

            ll min = added[xored];
            if(min<101)
                dp[value][min] += nums[i];
        }
    }

    ForA3(maxx+1)
    {
        for(int i=1;i<101;i++)
            dp[k][i] += dp[k][i-1];
    }

    ForA3(q)
    {
        string x;
        cin>>x;
        int m;
        cin>>m;
        int value =0;
        for(int j=0;j<x.size();j++)
        {
            if(x[j]=='1')
            {
                value+= powe[j];
            }
        }

        cout<<dp[value][m]<<endl;
    }

    return 0;
}