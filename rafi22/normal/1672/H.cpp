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

const bool multi=0;

int pref[200007][2][2];

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
        int n,q;
        string s;
        cin>>n>>q>>s;
        s='#'+s;
        set<int>S;
        S.insert(1);
        for(int i=2;i<=n;i++)
        {
            if(s[i]==s[i-1])
            {
                pref[i-1][s[*--S.end()]-'0'][s[i]-'0']++;
                S.insert(i);
            }
            for(int a=0;a<2;a++) for(int b=0;b<2;b++) pref[i][a][b]=pref[i-1][a][b];
        }
        pref[n][s[*--S.end()]-'0'][s[n]-'0']++;
        S.insert(n+1);
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            int x=*S.upper_bound(l);
            if(x>r)
            {
                cout<<1<<endl;
                continue;
            }
            int a1=s[l]-'0',b1=s[x-1]-'0';
            int y=*--S.upper_bound(r);
            int a2=s[y]-'0',b2=s[r]-'0';
            int c[2][2];
            int t=2;
            for(int a=0;a<2;a++)
            {
                for(int b=0;b<2;b++)
                {
                    c[a][b]=pref[y-1][a][b]-pref[x-1][a][b];
                    t+=c[a][b];
                }
            }
            c[a1][b1]++;
            c[a2][b2]++;
            int k=min(c[1][0],c[0][1])+min(c[0][0],c[1][1]);
            bool q=s[l]-'0';
            if(s[l]==s[r]&&min(c[1][0],c[0][1])>0&&c[q][q]<=c[!q][!q]) k--;
            else if(c[0][0]==c[1][1]&&c[0][1]==c[1][0]) k--;
            cout<<t-k<<endl;
        }
    }

    return 0;
}