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

int last[200];
bool is[200];

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
        memset(is,0,sizeof is);
        memset(last,0,sizeof last);
        for(auto x:s) is[x]=1;
        bool ok=1;
        for(int i=1;i<=sz(s);i++)
        {
            for(int j='a';j<='z';j++)
            {
                if(!is[j]||j==s[i-1]) continue;
                if(last[j]<last[s[i-1]]) ok=0;
            }
            last[s[i-1]]=i;
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}