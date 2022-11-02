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

const bool multi=0;

int a[100007];
int c[100007];
int p[100007];

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
        int n,s,S;
        cin>>n>>s;
        if(s<2*n-1||s>n*(n+1)/2)
        {
            cout<<"No";
            return 0;
        }
        cout<<"Yes"<<endl;
        int l=1,r=n,sr,k;
        while(l<=r)
        {
            sr=(l+r)/2;
            int x=n-1,sum=1;
            memset(a,0,sizeof a);
            a[1]=1;
            for(int i=2;x>0&&i<=n;i++)
            {
                a[i]=min(x,a[i-1]*sr);
                sum+=a[i]*i;
                x-=a[i];
            }
            if(sum<=s&&x==0)
            {
                k=sr;
                r=sr-1;
                for(int i=1;i<=n;i++) c[i]=a[i];
                S=s-sum;
            }
            else l=sr+1;
        }
       // cout<<k<<" "<<S<<endl;
        int it,j;
        for(int i=n;i>0;i--)
        {
            if(c[i]<2) continue;
            it=i;
            break;
        }
        for(int i=n;i>0;i--)
        {
            if(c[i]<1) continue;
            j=i+1;
            break;
        }
        for(;j<=n;j++)
        {
            if(S<j-it) break;
            S-=j-it;
            c[j]=1;
            c[it]--;
            if(c[it]==1) it--;
        }
        while(S--)
        {
            c[it]--;
            c[++it]++;
        }
        it=0;
        for(int i=2;i<=n;i++)
        {
            int x=k,l=1;
            for(int j=1;j<=c[i];j++)
            {
                p[it+c[i-1]+j]=it+l;
                x--;
                if(!x)
                {
                    l++;
                    x=k;
                }
            }
            it+=c[i-1];
        }
        for(int i=2;i<=n;i++) cout<<p[i]<<" ";
    }

    return 0;
}