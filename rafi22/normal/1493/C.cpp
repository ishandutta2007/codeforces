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

int cnt[26];
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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(n%k!=0)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=0;i<26;i++) cnt[i]=0;
        bool g=1;
        for(auto x:s) cnt[x-'a']++;
        for(int i=0;i<26;i++) if(cnt[i]%k!=0) g=0;
        if(g)
        {
            cout<<s<<endl;
            continue;
        }

        for(int i=sz(s)-1;i>=0;i--)
        {
            cnt[s[i]-'a']--;
            bool found=0;
            for(int z=s[i]-'a'+1;z<26;z++)
            {
                cnt[z]++;
                int sum=0;
                for(int j=0; j<26; j++)
                {
                    ile[j]=(k-cnt[j]%k)%k;
                    sum+=ile[j];
                }
                if(sum<=sz(s)-i-1&&(sz(s)-i-1-sum)%k==0)
                {
                    for(int j=0; j<i; j++) cout<<s[j];
                    cout<<(char)(z+'a');
                    for(int j=0; j<sz(s)-i-sum-1; j++) cout<<'a';
                    for(int j=0; j<26; j++)
                    {
                        for(int l=0; l<ile[j]; l++) cout<<(char)(j+'a');
                    }
                    cout<<endl;
                    found=1;
                    break;
                }
                cnt[z]--;
            }
            if(found) break;
        }
    }

    return 0;
}