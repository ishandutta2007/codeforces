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

int a[200007];
int add[200007];

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
        int n,k,sum=1;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i]-2;
        }
        if(sum<k)
        {
            cout<<-1;
            return 0;
        }
        sort(a+1,a+n+1,greater<int>());
        int it=1,all=0,act=0;
        add[0]=1;
        add[1]=-1;
        for(int j=0;; j++)
        {
            act+=add[j];
            for(int l=0; l<act&&it<=n; l++)
            {
                    // cout<<j<<" "<<a[it]<<endl;
                add[j+2]+=2;
                add[j+2+(a[it]-1)/2]--;
                add[j+2+(a[it]-1)/2+(a[it]-1)%2]--;
                it++;
                all--;
            }
            all+=act;
            act+=add[j+1];
            all+=act;
            act+=add[j+2];
            all+=act;
            if(all>=k)
            {
                cout<<j+2;
                return 0;
            }
            all-=act;
            act-=add[j+2];
            all-=act;
            act-=add[j+1];
        }
        // cout<<all<<endl;
    }

    return 0;
}