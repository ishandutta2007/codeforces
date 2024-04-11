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

const bool multi=0;

int DP[500007];
int seg[1000007];
set<pair<int,int>>s;

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
        int n,ans=0,act=0;
        cin>>n;
        string str; cin>>str; str='#'+str;
        s.insert({inf,0});
        for(int i=1;i<=n;i++)
        {
            if(str[i]=='0')
            {
                DP[i]=DP[i-1];
                while(!s.empty())
                {
                    pair<int,int> pr=*s.begin();
                    if(pr.st<=act) s.erase(s.begin());
                    else break;
                }
                s.insert({act,i-act});
                act=0;
            }
            else
            {
                act++;
               // cout<<act<<endl;
                pair<int,int> pr=*(s.upper_bound({act,0}));
               // cout<<pr.st<<" "<<pr.nd<<endl;
                if(pr.st!=inf)
                    DP[i]=DP[i-1]+i-pr.nd-(pr.st-act);
                else DP[i]=DP[i-1]+i;
            }
            ans+=DP[i];
        }
        cout<<ans;

    }

    return 0;
}