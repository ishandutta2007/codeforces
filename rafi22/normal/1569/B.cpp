#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
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

bool ans[107][107];
char c[107][107];

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
        memset(ans,0,sizeof ans);
        int n;
        cin>>n;
        string s;
        cin>>s;
        s='#'+s;
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='2') v.pb(i);
        }
        if(sz(v)==1||sz(v)==2) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;

            for(int i=1;i<sz(v);i++) ans[v[i-1]][v[i]]=1;
            if(sz(v)>0)  ans[v[sz(v)-1]][v[0]]=1;

            for(int i=1;i<=n;i++)
            {
                for(int j=i;j<=n;j++)
                {
                    if(i==j) c[i][j]='X';
                    else if(s[i]=='1'||s[j]=='1') c[i][j]='=';
                    else if(ans[i][j]) c[i][j]='+';
                    else c[i][j]='-';
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<i;j++)
                {
                    if(c[j][i]=='-') c[i][j]='+';
                    if(c[j][i]=='+') c[i][j]='-';
                    if(c[j][i]=='=') c[i][j]='=';
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++) cout<<c[i][j];
                cout<<endl;
            }
        }
    }

    return 0;
}