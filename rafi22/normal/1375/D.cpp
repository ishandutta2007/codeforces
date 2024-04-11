#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

int tab[1007];
set <int> cnt;
vector <int> ans;
set <int> kolejka;
int n;

int mex()
{
    for(int i=0;i<=n+3;i++)
    {
        cnt.insert(i);
    }
    for(int i=0;i<n;i++) cnt.erase(tab[i]);
    return *cnt.begin();
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ans.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>tab[i];
            if(tab[i]!=i) kolejka.insert(i);
        }
        int a=kolejka.size();
        for(int i=0;i<a;i++)
        {
            int p=*kolejka.begin(),m=mex();
            if(m==n)
            {
                ans.push_back(p);
                m=tab[p];
                tab[p]=n;
            }
            ans.push_back(m);
            kolejka.erase(m);
            tab[m]=m;
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++) cout<<ans[i]+1<<" ";
        cout<<endl;
    }

    return 0;
}