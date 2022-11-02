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

int ile[200007][26];


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
        s='#'+s;
        for(int i=1;i<sz(s);i++)
        {
            for(int j=0;j<26;j++) ile[i][j]=ile[i-1][j];
            ile[i][s[i]-'a']++;
        }
        int q,l,r;
        cin>>q;
        while(q--)
        {
            cin>>l>>r;
            if(l==r) cout<<"Yes"<<endl;
            else
            {
                if(s[l]!=s[r]) cout<<"Yes"<<endl;
                else
                {
                    int cnt=0;
                    for(int i=0;i<26;i++) if(ile[r][i]-ile[l-1][i]>0) cnt++;
                    if(cnt>2) cout<<"Yes"<<endl;
                    else cout<<"No"<<endl;
                }
            }
        }
    }

    return 0;
}