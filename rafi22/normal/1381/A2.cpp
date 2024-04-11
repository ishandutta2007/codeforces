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

const bool multi=1;

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
        string a,b;
        cin>>a>>b;
        vector <int> ans;
        vector <int> ans1;
        for(int i=1;i<n;i++)
        {
            if(a[i]!=a[i-1]) ans.push_back(i);
        }
        if(a[n-1]=='1') ans.push_back(n);
        for(int i=1;i<n;i++)
        {
            if(b[i]!=b[i-1]) ans1.push_back(i);
        }
        if(b[n-1]=='1') ans1.push_back(n);
        reverse(ans1.begin(),ans1.end());
        cout<<ans.size()+ans1.size()<<" ";
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        for(int i=0;i<ans1.size();i++) cout<<ans1[i]<<" ";
        cout<<endl;
    }

    return 0;
}