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

int cnt[26];

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
        memset(cnt,0,sizeof cnt);
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        for(auto x:s) cnt[x-'a']++;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<min(26LL,n/k+1);j++)
            {
                if(cnt[j]==0||j==n/k)
                {
                    cout<<(char)(j+'a');
                    break;
                }
                cnt[j]--;
            }
        }
        cout<<endl;
    }

    return 0;
}