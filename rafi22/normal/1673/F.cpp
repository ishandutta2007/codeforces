#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
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

const bool multi=0;

int a[40][40];
int X[40*40],Y[40*40];

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
        int n,k;
        cin>>n>>k;
        for(int l=0;l<5;l++)
        {
            int x=(1<<l);
            for(int i=0;i<x;i++)
            {
                for(int j=0;j<x;j++)
                {
                    a[i][2*x-j-1]=a[i][j]+(1<<(2*l));
                }
            }
            for(int i=0;i<x;i++)
            {
                for(int j=0;j<2*x;j++)
                {
                    a[2*x-i-1][j]=a[i][j]+(1<<(2*l+1));
                }
            }
        }
        int sum=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n-1; j++)
            {
                cout<<(a[i][j]^a[i][j+1])<<" ";
            }
            cout<<endl;
        }
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<(a[i][j]^a[i+1][j])<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                X[a[i][j]]=i;
                Y[a[i][j]]=j;
            }
        }
        int x=0,y=0;
        while(k--)
        {
            int c;
            cin>>c;
            c^=a[x][y];
            x=X[c],y=Y[c];
            cout<<x+1<<" "<<y+1<<endl;
        }
    }

    return 0;
}