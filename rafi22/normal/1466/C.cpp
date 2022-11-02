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

int a[100007];

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
        string s;
        cin>>s;
        int n=sz(s);
        s="##"+s+"##";
        int ans=0;
        for(int i=2;i<=n+1;i++)
        {
            set<char> let;
            for(int j='a';j<='z';j++) let.insert((char)j);
            if(s[i]==s[i-1]||s[i]==s[i-2])
            {
                let.erase(s[i-1]);
                let.erase(s[i-2]);
                let.erase(s[i+1]);
                let.erase(s[i+2]);
                ans++;
                s[i]=*let.begin();
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}