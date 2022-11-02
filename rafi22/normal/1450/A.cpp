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
int ile[26];

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
        for(int i=0;i<n;i++) ile[s[i]-'a']++;
        for(int i=0;i<26;i++)
        {
            if(i!='t'-'a')
            {
                for(int j=0;j<ile[i];j++) cout<<(char)('a'+i);
            }
        }
        for(int j=0;j<ile['t'-'a'];j++) cout<<'t';
        cout<<endl;

        for(int i=0;i<26;i++) ile[i]=0;

    }

    return 0;
}