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

int tab[1007];

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
        int n,a;
        cin>>n;
        set <int> s,s1;
        for(int i=1;i<=n;i++) s.insert(i);
        for(int i=1;i<=n;i++) cin>>tab[i];
        s1.insert(tab[1]);
        s.erase(tab[1]);
        int x,y,z;
        bool is=0;
        for(int i=2;i<n;i++)
        {
            a=tab[i];
            if(*s1.begin()<a&&*s.begin()<a)
            {
                is=1;
                y=i;
                for(int j=i-1;j>0;j--)
                {
                    if(tab[j]==*s1.begin())
                    {
                        x=j;
                        break;
                    }
                }
                for(int j=i+1;j<=n;j++)
                {
                    if(tab[j]==*s.begin())
                    {
                        z=j;
                        break;
                    }
                }
                break;
            }
            s1.insert(a);
            s.erase(a);
        }
        if(is) cout<<"YES"<<endl<<x<<" "<<y<<" "<<z<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}