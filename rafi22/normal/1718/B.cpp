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


int F[107];
int cnt[107][77];
int x[107];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    F[0]=1;
    F[1]=1;
    for(int i=2;i<=70;i++) F[i]=F[i-1]+F[i-2];
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        bool ok=1;
        int S=0,k;
        cin>>k;
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<=k;i++)
        {
            int a;
            cin>>a;
            x[i]=a;
            S+=a;
            for(int j=70;j>=0;j--)
            {
                if(a>=F[j])
                {
                    cnt[i][j]++;
                    a-=F[j];
                }
            }
            if(a>0) ok=0;
        }
        int p=0,l=-1;
        for(int i=0;i<=70;i++)
        {
            p+=F[i];
            if(p==S)
            {
                l=i;
                break;
            }
        }
        if(l==-1) ok=0;
        int last=-1;
        for(int j=70;j>=0;j--)
        {
            if(j<=l)
            {
                int c=-1;
                for(int i=1; i<=k; i++)
                {
                    if(last!=i&&cnt[i][j]>0)
                    {
                        if(c==-1||x[i]>x[c]) c=i;
                    }
                }
                if(c==-1)
                {
                    ok=0;
                    break;
                }
                cnt[c][j]--;
                last=c;
                x[c]-=F[j];
            }
            for(int i=1; i<=k; i++)
            {
                if(cnt[i][j]>0)
                {
                    if(j==0) ok=0;
                    if(j==1)
                    {
                        cnt[i][j-1]++;
                    }
                    if(j>1)
                    {
                        cnt[i][j-1]++;
                        cnt[i][j-2]++;
                    }
                }
            }
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}