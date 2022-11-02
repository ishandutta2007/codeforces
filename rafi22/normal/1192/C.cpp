#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ll long long
ll mod=998244353;
int inf=1000000007;
ll infl=1000000000000000007;

const int M=65,S=11;

int id[200];
ll cnt[S][M][M];
ll ways[S][M][M][M];
ll fac[5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int it=0;
    for(int i='a';i<='z';i++) id[i]=it++;
    for(int i='A';i<='Z';i++) id[i]=it++;
    for(int i='0';i<='9';i++) id[i]=it++;
    set<string>S;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        S.insert(s);
        reverse(all(s));
        S.insert(s);
    }
    for(auto x:S) cnt[sz(x)][id[(int)x[0]]][id[(int)x.back()]]++;
    int m=62;
    for(int s=3;s<=10;s++)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=i; j<m; j++)
            {
                for(int k=j; k<m; k++)
                {
                    for(int l=0; l<m; l++)
                    {
                        ways[s][i][j][k]=(ways[s][i][j][k]+cnt[s][i][l]*cnt[s][j][l]%mod*cnt[s][k][l])%mod;
                    }
                }
            }
        }
    }
    fac[0]=1;
    for(int i=1;i<=4;i++) fac[i]=fac[i-1]*i;
    ll ans=0;
    for(int s=3;s<=10;s++)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=i; j<m; j++)
            {
                for(int k=j; k<m; k++)
                {
                    for(int l=k; l<m; l++)
                    {
                        ll ile=24,c=1;
                        if(j!=i)
                        {
                            ile/=fac[c];
                            c=1;
                        }
                        else c++;
                        if(k!=j)
                        {
                            ile/=fac[c];
                            c=1;
                        }
                        else c++;
                        if(l!=k)
                        {
                            ile/=fac[c];
                            c=1;
                        }
                        else c++;
                        ile/=fac[c];
                        ans=(ans+ile*ways[s][i][j][k]%mod*ways[s][i][j][l]%mod*ways[s][i][k][l]%mod*ways[s][j][k][l])%mod;
                    }
                }
            }
        }
    }
    cout<<ans;

    return 0;
}