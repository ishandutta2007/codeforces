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

char ans[1000007];

vector<int>lit[200];
bool take[200];
bool ntake[200];
char res[200];
char nres[200];

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
        int k,K;
        cin>>k;
        K=k+'a'-1;
        for(int i='a';i<=K;i++)
        {
            lit[i].clear();
            take[i]=0;
            res[i]=0;
        }
        string s,a,b;
        cin>>s>>a>>b;
        int n=sz(s);
        for(int i=0;i<n;i++) ans[i]=0;
        for(int i=n-1;i>=0;i--) lit[s[i]].pb(i);
        bool bad=0,czy=0;
        int mx=K;
        for(int i=0;i<n;i++)
        {
            if(ans[i])
            {
                if(ans[i]>a[i]) czy=1;
                continue;
            }
            char j='a';
            if(!czy) j=a[i];
            bool is=0;
            for(;j<=K;j++)
            {
                if(take[j]) continue;
                if(!czy&&j==a[i])
                {
                    bool nie=0;
                    for(int l='a';l<=K;l++)
                    {
                        ntake[l]=take[l];
                        nres[l]=res[l];
                    }
                    int nmx=mx;
                    ntake[j]=1;
                    nres[s[i]]=j;
                    while(ntake[nmx]) nmx--;
                    for(int l=i+1;l<n;l++)
                    {
                        if(nres[s[l]]&&nres[s[l]]==a[l]) continue;
                        if(nres[s[l]]&&nres[s[l]]>a[l]) break;
                        if(!nres[s[l]]&&nmx>a[l]) break;
                        if(nres[s[l]]&&nres[s[l]]<a[l]){nie=1;break;}
                        if(!nres[s[l]]&&nmx<a[l]){nie=1;break;}
                        if(ntake[a[l]]){nie=1;break;}
                        ntake[a[l]]=1;
                        nres[s[l]]=a[l];
                        while(ntake[nmx]) nmx--;
                    }
                    if(nie) continue;
                }
                for(auto x:lit[s[i]]) ans[x]=j;
                take[j]=1;
                res[s[i]]=j;
                if(j>a[i]) czy=1;
                is=1;
                while(take[mx]) mx--;
                break;
            }
            if(!is)
            {
                bad=1;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i]>b[i]) bad=1;
            if(ans[i]<b[i]) break;
        }
        if(bad)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        vector<int>free;
        for(int i='a';i<=K;i++) if(!take[i]) free.pb(i);
        for(int i='a';i<=K;i++)
        {
            if(!res[i])
            {
                res[i]=free.back();
                free.pop_back();
            }
        }
        for(int i='a';i<=K;i++) cout<<res[i];
        cout<<endl;
    }

    return 0;
}