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
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool nie=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                cout<<i<<" "<<i+1<<endl;
                nie=0;
                break;
            }
        }
        if(nie) cout<<-1<<" "<<-1<<endl;
    }

    return 0;
}