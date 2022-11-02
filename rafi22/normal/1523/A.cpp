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

int a[1007],b[1007];

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
        int n,m;
        cin>>n>>m;
        string s,ns;
        cin>>s;
        s='0'+s+'0';
        for(int i=0;i<min(m,n);i++)
        {
            ns=s;
            for(int j=1;j<=n;j++)
            {
                int x=(s[j-1]=='1')+(s[j+1]=='1');
                if(s[j]=='0'&&x==1) ns[j]='1';
            }
            s=ns;
        }
        for(int i=1;i<=n;i++) cout<<s[i];
        cout<<endl;
    }

    return 0;
}