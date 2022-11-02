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

int a[100007];
int cnt1[100007],cnt2[100007],ile;

void add(int l,int r)
{
    ile++;
    if(l==r)
    {
        cnt2[l]++;
        cnt1[l]++;
    }
    else
    {
        cnt1[l]++;
        cnt1[r]++;
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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int poc=a[1],mx=-1,p=-1,can=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==a[i-1])
            {
                add(poc,a[i]);
                poc=a[i];
            }
        }
        add(poc,a[n]);
        for(int i=1;i<=n;i++)
        {
            if(cnt2[i]>mx)
            {
                mx=cnt2[i];
                p=i;
            }
        }
        for(int i=2;i<=n;i++) if(a[i]!=a[i-1]&&a[i]!=p&&a[i-1]!=p) can++;
       // cout<<cnt2[p]<<" "<<ile<<" "<<cnt1[p]<<endl;
        if(can<cnt2[p]-1-(ile-cnt1[p])) cout<<-1<<endl;
        else cout<<ile-1+max(0LL,cnt2[p]-1-(ile-cnt1[p]))<<endl;
        ile=0;
        for(int i=1;i<=n;i++)
        {
            cnt1[i]=0;
            cnt2[i]=0;
        }
    }

    return 0;
}