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

char tab[57][57];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<=50;i++)
        {
            for(int j=0;j<=50;j++)
            {
                tab[i][j]='0';
            }
        }
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        if(n*a!=m*b)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<a;j++)
            {
                tab[i][(j+i*(m/__gcd(n,m)))%m]='1';
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<tab[i][j];
            }
            cout<<endl;
        }
    }

    return 0;
}