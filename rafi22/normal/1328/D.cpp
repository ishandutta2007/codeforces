#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define pob pop_back
using namespace std;

double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,c,last,p;
        cin>>n;
        int tab[n];
        int ans[n];
        for(int i=0;i<n;i++) cin>>tab[i];
        bool x=0,y=1;
        last=tab[0];
        for(int i=0;i<n;i++)
        {
            if(!x&&tab[i]==tab[(i+1)%n])
            {
                ans[i]=i%2+1;
                ans[i+1]=i%2+1;
                x=1;
                p=i;
            }
            if(tab[i]!=last) y=0;
        }
        if(y)
        {
            cout<<1<<endl;
            for(int i=0;i<n;i++) ans[i]=1;
        }
        else if(n%2==0)
        {
            cout<<2<<endl;
            for(int i=0;i<n;i++) ans[i]=i%2+1;
        }
        else if(x)
        {
            cout<<2<<endl;
            for(int i=0;i<p;i++)
            {
                ans[i]=i%2+1;
            }
            for(int i=p+2;i<n;i++)
            {
                ans[i]=!(i%2)+1;
            }
        }
        else
        {
            cout<<3<<endl;
            for(int i=0;i<n-1;i++)
            {
                ans[i]=i%2+1;
            }
            ans[n-1]=3;
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}