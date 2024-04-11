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
        string s;
        cin>>s;
        s='#'+s;
        int c=0;
        for(auto x:s) if(x=='0') c++;
        if(s[1]=='0'||s[n]=='0'||c%2==1) cout<<"No"<<endl;
        else
        {
            cout<<"Yes"<<endl;
            int c1=0;
            string a1="",a2="";
            for(int i=1;i<=n;i++)
            {
                if(s[i]=='1')
                {
                    if(i-c1>(n-c)/2)
                    {
                        a1+=')';
                        a2+=')';
                    }
                    else
                    {
                        a1+='(';
                        a2+='(';
                    }
                }
                else
                {
                    c1++;
                    if(c1%2==1)
                    {
                        a1+='(';
                        a2+=')';
                    }
                    else
                    {
                        a1+=')';
                        a2+='(';
                    }
                }
            }
            cout<<a1<<endl<<a2<<endl;
        }
    }

    return 0;
}