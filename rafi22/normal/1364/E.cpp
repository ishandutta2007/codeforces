#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int ans[2500];

bool is[2500][2500];
int tab[2500][2500];

int querry(int a,int b)
{
    if(is[min(a,b)][max(a,b)])
    {
        return tab[min(a,b)][max(a,b)];
    }
    cout<<"? "<<a<<" "<<b<<endl;
    fflush(stdout);
    int x;
    cin>>x;
    if(x==-1) exit(0);
    is[min(a,b)][max(a,b)]=1;
    tab[min(a,b)][max(a,b)]=x;
    return x;
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
        int n,a,b,act,zero;
        cin>>n;
        vector <int> v;
        for(int i=1;i<=n;i++) v.pb(i);
        random_shuffle(v.begin(), v.end());
        a=v[0];
        b=v[1];
        act=querry(a,b);
        for(int i=2;i<n;i++)
        {
            int x=querry(b,v[i]);
            if(act>x)
            {
                a=v[i];
                act=x;
            }
            else if(act==x)
            {
                b=v[i];
                act=querry(a,b);
            }
        }
        random_shuffle(v.begin(), v.end());
        for(int i=0;i<n;i++)
        {
            if(v[i]==a||v[i]==b) continue;
            int x1=querry(a,v[i]),x2=querry(b,v[i]);
            if(x1<x2)
            {
                zero=a;
                break;
            }
            if(x1>x2)
            {
                zero=b;
                break;
            }
        }
        ans[zero]=0;

        for(int i=1;i<=n;i++)
        {
            if(i==zero) continue;
            ans[i]=querry(i,zero);
        }
        cout<<"! ";
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;


    }

    return 0;
}