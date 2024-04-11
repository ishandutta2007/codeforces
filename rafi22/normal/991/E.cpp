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

int cnt[15];
int s[25];

int dig(int n)
{
    if(n==0) return 0;
    cnt[n%10]++;
    return 1+dig(n/10);
}
int res=0;
int calc(vector<int>ile)
{
    int a=0;
    for(int i=0;i<10;i++) a+=ile[i];

    int ans=s[a];
    for(int i=0; i<10; i++) ans/=s[ile[i]];
    int x=s[a-1];
    if(ile[0]>0)
    {
        ile[0]--;
        for(int i=0; i<10; i++) x/=s[ile[i]];
        ans-=x;
    }
    return ans;
    //cout<<ans<<endl;
}

void go(int j,vector<int>ile)
{
    if(j==10)
    {
        res+=calc(ile);
        return;
    }
    if(ile[j]==0) go(j+1,ile);
    for(int i=ile[j];i>0;i--)
    {
        vector<int>ne=ile;
        ne[j]=i;
        go(j+1,ne);
    }
}

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
        s[0]=1;
        for(int i=1;i<=20;i++) s[i]=s[i-1]*i;
        int n;
        cin>>n;
        int a=dig(n);
        vector<int>xd;
        for(int i=0;i<10;i++) xd.pb(cnt[i]);
        go(0,xd);
        cout<<res<<endl;


    }

    return 0;
}