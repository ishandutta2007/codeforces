#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
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

int ans[10007];
int querry(int x,int y)
{
    int a;
    cout<<"? "<<x<<" "<<y<<endl;
    fflush(stdout);
    cin>>a;
    return a;
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
        set<int> s;
        for(int i=1;i<=n;i++) s.insert(i);
        while(sz(s)>1)
        {
            int a=querry(*s.begin(),*(--s.end())),b=querry(*(--s.end()),*s.begin());
            if(a>b)
            {

                ans[*s.begin()]=a;
                s.erase(s.begin());
            }
            else
            {
                ans[*(--s.end())]=b;
                s.erase(--s.end());
            }
        }
        ans[*s.begin()]=n;
        cout<<"! ";
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
        fflush(stdout);
    }

    return 0;
}