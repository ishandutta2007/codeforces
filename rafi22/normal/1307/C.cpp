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

const bool multi=0;


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
        int ans=0;
        for(int i='a';i<='z';i++)
        {
            int cnt=0;
            for(auto x:s) if(x==i) cnt++;
            ans=max(ans,cnt);
        }
        for(int i='a';i<='z';i++)
        {
            for(int j='a';j<='z';j++)
            {
                int cnt=0,ci=0;
                for(auto x:s)
                {
                    if(x==j) cnt+=ci;
                    if(x==i) ci++;
                }
                ans=max(ans,cnt);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}