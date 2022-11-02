#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

char arr[207][207];
bool is[207][207];
int n;

bool check(int x,int y,int x1,int y1)
{
    if(arr[x][y]=='0') arr[x][y]='1';
    else arr[x][y]='0';
    if(arr[x1][y1]=='0') arr[x1][y1]='1';
    else arr[x1][y1]='0';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1&&j==1) continue;
            is[i][j]=0;
            if(arr[i-1][j]=='S'||(arr[i-1][j]==arr[i][j]&&is[i-1][j])) is[i][j]=1;
            if(arr[i][j-1]=='S'||(arr[i][j-1]==arr[i][j]&&is[i][j-1])) is[i][j]=1;
        }
    }
    if(arr[x][y]=='0') arr[x][y]='1';
    else arr[x][y]='0';
    if(arr[x1][y1]=='0') arr[x1][y1]='1';
    else arr[x1][y1]='0';

    if(!is[n-1][n]&&!is[n][n-1])
    {
        if(x1==0&&x==0)
        {
            cout<<0<<endl;
        }
        else if(x1==0)
        {
            cout<<1<<endl;
            cout<<x<<" "<<y<<endl;
        }
        else
        {
            cout<<2<<endl;
            cout<<x<<" "<<y<<endl;
            cout<<x1<<" "<<y1<<endl;
        }
    }
    return !is[n-1][n]&&!is[n][n-1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>arr[i][j];
            }
        }
        if(check(0,0,0,0)) continue;
        if(check(1,2,0,0)) continue;
        if(check(2,1,0,0)) continue;
        if(check(n-1,n,0,0)) continue;
        if(check(n,n-1,0,0)) continue;
        if(check(1,2,2,1)) continue;
        if(check(1,2,n-1,n)) continue;
        if(check(1,2,n,n-1)) continue;
        if(check(2,1,n-1,n)) continue;
        if(check(2,1,n,n-1)) continue;
        if(check(n-1,n,n,n-1)) continue;
    }

    return 0;
}