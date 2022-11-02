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

int tab[307][307];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>tab[i][j];
                int act=4;
                if(i==1||i==n) act--;
                if(j==1||j==m) act--;
                if(tab[i][j]>act)
                {
                    ok=0;
                }
                tab[i][j]=act;
            }
        }
        if(!ok) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=m; j++)
                {
                    cout<<tab[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }



    return 0;
}