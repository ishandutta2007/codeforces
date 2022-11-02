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

int nim[500007];
bool is[1007];



signed main()
{
    for(int i=2;i<=300;i++)
    {
        memset(is,0,sizeof is);
        for(int j=0;j<=i-2;j++)
        {
            is[nim[j]^nim[i-j-2]]=1;
        }
        for(int j=0;j<=10000;j++)
        {
            if(!is[j])
            {
                nim[i]=j;
                break;
            }
        }
    }
    for(int i=301;i<=500000;i++) nim[i]=nim[i-102];
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n;
        string s;
        cin>>n>>s;
        int cr=0,cb=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R') cr++;
            else cb++;
        }
        vector<int>V;
        int c=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1]) c++;
            else
            {
                if(c>0) V.pb(c);
                c=0;
            }
        }
        if(c>0) V.pb(c);
        int is=0;
        for(auto x:V)
        {
            int y=x+1;
            is^=nim[y];
        }
        if(cr>cb) cout<<"Alice"<<endl;
        else if(cr<cb) cout<<"Bob"<<endl;
        else if(is>0) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }

    return 0;
}