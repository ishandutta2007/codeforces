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
        memset(ile,0,sizeof ile);
        string s,t;
        cin>>s>>t;
        for(auto x:s) ile[x-'a']++;
        if(t=="abc"&&ile[0])
        {
            while(ile[0]--) cout<<(char)(0+'a');
            while(ile[2]--) cout<<(char)(2+'a');
            while(ile[1]--) cout<<(char)(1+'a');
            for(int i=3;i<26;i++)
            {
                while(ile[i]--) cout<<(char)(i+'a');
            }
        }
        else
        {
            for(int i=0;i<26;i++)
            {
                while(ile[i]--) cout<<(char)(i+'a');
            }
        }
        cout<<endl;
    }

    return 0;
}