#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define double long double
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int a[100007];
int pos[100007];
int len[100007];

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
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pos[a[i]]=i;
        }
        for(int i=1;i<=n;i++) len[i]=1;
        for(int i=1;i<=n;i++)
        {
            int j=pos[i];
            if(a[j+1]>i) len[j+1]=max(len[j+1],len[j]+1);
            if(a[j-1]>i) len[j-1]=max(len[j-1],len[j]+1);
        }
        multiset<int>s;
        for(int i=1;i<=n;i++) s.insert(len[i]);
        for(int i=2;i<n;i++)
        {
            if(a[i]>a[i-1]&&a[i]>a[i+1]&&len[i-1]==len[i+1])
            {
                s.erase(s.find(len[i]));
                if(*(--s.end())<len[i]&&len[i]%2==1) ans++;
                s.insert(len[i]);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}