#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;
char tab[307][307];
char ans[307][307];
int n,cnt;

void fil()
{
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ans[i][j]=tab[i][j];
        }
    }
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
        int k=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>tab[i][j];
                if(tab[i][j]=='X') k++;
            }
        }
        fil();
        for(int i=1;i<=n;i++)
        {
            int j;
            if(i%3==1) j=3;
            if(i%3==2) j=2;
            if(i%3==0) j=1;
            for(;j<=n;j+=3)
            {
                if(tab[i][j]=='X')
                {
                    ans[i][j]='O';
                    cnt++;
                }
            }
        }
        if(cnt>k/3)
        {
            fil();
            for(int i=1; i<=n; i++)
            {
                int j;
                if(i%3==1) j=1;
                if(i%3==2) j=3;
                if(i%3==0) j=2;
                for(; j<=n; j+=3)
                {
                    if(tab[i][j]=='X')
                    {
                        ans[i][j]='O';
                        cnt++;
                    }
                }
            }
            if(cnt>k/3)
            {
                fil();
                for(int i=1; i<=n; i++)
                {
                    int j;
                    if(i%3==1) j=2;
                    if(i%3==2) j=1;
                    if(i%3==0) j=3;
                    for(; j<=n; j+=3)
                    {
                        if(tab[i][j]=='X')
                        {
                            ans[i][j]='O';
                            cnt++;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }

    return 0;
}