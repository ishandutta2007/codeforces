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
#define vll vector<ll>
#define F first
#define S second
#define debug(x)    cerr << #x << " = " << x << endl;
#define mem(x) memset(x,-1,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;
ll n;
ll table[1005][1005];
ll dp2[1005][1005];
ll dp5[1005][1005];
char an2[1005][1005];
char an5[1005][1005];
vector<char> ans;
ll getdp2(ll row, ll col)
{
    if(dp2[row][col]!=-1)
        return dp2[row][col];
    
    ll base;
    if(row==0)
    {
        base = getdp2(row,col-1);
        an2[row][col]='R';
    }
    else if(col==0)
    {
        base = getdp2(row-1,col);
        an2[row][col]='D';
    }
    else
    {
        base = min(getdp2(row-1,col),getdp2(row,col-1));
        if(base==getdp2(row-1,col))
        {
            an2[row][col]='D';
        }
        else
        {
            an2[row][col]='R';
        }
    }
    ll num = table[row][col];
    ll counter = 0;
    while(num%2==0)
    {
        num/=2;
        counter++;
    }
    dp2[row][col] = base+counter;
    return base+counter;
}

ll getdp5(ll row, ll col)
{
    if(dp5[row][col]!=-1)
        return dp5[row][col];
    
    ll base;
    if(row==0)
    {
        base = getdp5(row,col-1);
        an5[row][col]='R';
    }
    else if(col==0)
    {
        base = getdp5(row-1,col);
        an5[row][col]='D';
    }
    else
    {
        base = min(getdp5(row-1,col),getdp5(row,col-1));
        if(base==getdp5(row-1,col))
        {
            an5[row][col]='D';
        }
        else
        {
            an5[row][col]='R';
        }
    }
    ll num = table[row][col];
    ll counter = 0;
    while(num%5==0)
    {
        num/=5;
        counter++;
    }
    dp5[row][col] = base+counter;
    return base+counter;
}

int getans2()
{
    ll row = n-1;
    ll col = n-1;
    
    while(row!=0 || col!=0)
    {
        ans.push_back(an2[row][col]);
        if(an2[row][col]=='D')
            row--;
        else
            col--;
    }
    return 0;
}

int getans5()
{
    ll row = n-1;
    ll col = n-1;
    
    while(row!=0 || col!=0)
    {
        ans.push_back(an5[row][col]);
        if(an5[row][col]=='D')
            row--;
        else
            col--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    
    ll iszero=0;
    ll x,y;
    ForA1(n)
    {
        ForA2(n)
        {
            cin>>table[i][j];
            if(table[i][j]==0)
            {
                table[i][j] = 10;
                iszero=1;
                x =i;
                y = j;
            }
        }
    }
    mem(dp2);
    mem(dp5);
    ll num = table[0][0];
    ll counter = 0;
    while(num%5==0)
    {
        num/=5;
        counter++;
    }
    dp5[0][0] = counter;
    
    num = table[0][0];
    counter = 0;
    while(num%2==0)
    {
        num/=2;
        counter++;
    }
    dp2[0][0] = counter;
    
    ll answer = min(getdp2(n-1,n-1),getdp5(n-1,n-1));
    
    if(answer>1 && iszero==1)
    {
        cout<<1<<endl;
        // cout<<x<<y<<endl;
        for(int i=0;i<x;i++)
        {
            cout<<'D';
        }
        for(int i=0;i<y;i++)
        {
            cout<<'R';
        }
        for(int i=x;i<n-1;i++)
        {
            cout<<'D';
        }
        for(int i=y;i<n-1;i++)
        {
            cout<<'R';
        }
        return 0;
    }
    
    cout<<answer<<endl;
    
    // ForA1(n)
    // {
    //     ForA2(n)
    //     {
    //         cout<<an5[i][j];
    //     }
    //     cout<<endl;
    // }
    
    // cout<<5;
    if(answer==getdp2(n-1,n-1))
    {
        getans2();
    }
    else
    {
        getans5();
    }
    
    n = ans.size();
    for(ll i=n-1;i>=0;i--)
    {
        cout<<ans[i];
    }
    cout<<endl;

    return 0;
}