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
        int n,k;
        cin>>n>>k;
        k--;
        string s;
        cin>>s;
        s='#'+s;
        vector<pair<int,int>>ans;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='(')
            {
                ans.pb({cnt+1,i});
                reverse(s.begin()+cnt+1,s.begin()+i+1);
                cnt++;
            }
        }
        for(int i=0;i<k;i++)
        {
            for(int j=2*i+2;j<=n;j++)
            {
                if(s[j]==')')
                {
                    ans.pb({2*i+2,j});
                    reverse(s.begin()+2*i+2,s.begin()+j+1);
                    break;
                }
            }
        }
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x.st<<" "<<x.nd<<endl;
    }

    return 0;
}