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

const int N=507;

int a[N],b[N];
int id[N];
vector<pair<int,int>>ans;

void mov(int l,int r)
{
    ans.pb({l,r});
    reverse(a+l,a+r+1);
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
        for(int i=1;i<=n;i++) cin>>b[i];
        bool zle=0;
        ans.clear();
        if(a[1]!=b[1]||a[n]!=b[n]) zle=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==b[i]) continue;
            bool is=0;
            for(int j=i;j<n;j++)
            {
                if(a[j]==b[i]&&a[j+1]==b[i-1])
                {
                    is=1;
                    mov(i-1,j+1);
                    break;
                }
            }
            if(is) continue;
            for(int j=i;j<n;j++)
            {
                if(a[j]==b[i-1]&&a[j+1]==b[i])
                {
                    memset(id,0,sizeof id);
                    for(int l=i-1;l<j;l++) id[a[l]]=l;
                    for(int l=j+1;l<=n;l++)
                    {
                        if(id[a[l]]>0)
                        {
                            mov(id[a[l]],l);
                            break;
                        }
                    }
                    break;
                }
            }
            for(int j=i;j<n;j++)
            {
                if(a[j]==b[i]&&a[j+1]==b[i-1])
                {
                    is=1;
                    mov(i-1,j+1);
                    break;
                }
            }
            if(!is) zle=1;
        }
        if(zle)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl<<sz(ans)<<endl;
        for(auto x:ans) cout<<x.st<<" "<<x.nd<<endl;
    }

    return 0;
}