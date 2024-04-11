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

int tab[100007];

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
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]=='0'&&b[i]=='1')
            {
                //cout<<'x'<<endl;
                if(a[0]!='0')
                {
                    ans.push_back(1);
                    a[0]='0';
                }
                ans.push_back(i+1);
                for(int j=0;j<=i;j++)
                {
                    if(a[j]=='1') a[j]='0';
                    else a[j]='1';
                }
                for(int j=0;j<=i/2;j++)
                {
                    swap(a[j],a[i-j]);
                }
            }
            else if(a[i]=='1'&&b[i]=='0')
            {
                if(a[0]!='1')
                {
                    ans.push_back(1);
                    a[0]='1';
                }
                ans.push_back(i+1);
                for(int j=0;j<=i;j++)
                {
                    if(a[j]=='1') a[j]='0';
                    else a[j]='1';
                }
                for(int j=0;j<=i/2;j++)
                {
                    swap(a[j],a[i-j]);
                }
            }
            //cout<<a<<endl;
        }
        //cout<<a<<" "<<b<<endl;
        cout<<ans.size()<<" ";
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;

    }

    return 0;
}