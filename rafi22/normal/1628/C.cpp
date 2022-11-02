#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int a[1007][1007];
bool b[1007][1007];
bool c[1007][1007];
int n;

void ustaw1(int x,int y)
{
    b[x][y]=1;
    b[n-y+1][n-x+1]=1;
    c[x+1][y]^=1;
    c[x-1][y]^=1;
    c[x][y+1]^=1;
    c[x][y-1]^=1;
}
void ustaw2(int x,int y)
{
    b[x][y]=1;
    b[y][x]=1;
    c[x+1][y]^=1;
    c[x-1][y]^=1;
    c[x][y+1]^=1;
    c[x][y-1]^=1;
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
                cin>>a[i][j];
                b[i][j]=0;
                c[i][j]=0;
            }
        }
        for(int i=2;i<=n;i+=2)
        {
            ustaw1(1,i);
            for(int j=2;j<=i;j++) if(!c[j-1][i-j+1]) ustaw1(j,i-j+1);
        }
        for(int i=n-1;i>0;i-=2)
        {
            ustaw2(i,1);
            for(int j=2;j<=n-i+1;j++) if(!c[i+j-1][j-1]) ustaw2(i+j-1,j);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(b[i][j]) ans^=a[i][j];
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}