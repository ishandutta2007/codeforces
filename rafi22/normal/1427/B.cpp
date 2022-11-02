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
       int n,k,ans=0,l=0,p=0;
       bool b=0;
       cin>>n>>k;
       vector <int> v;
       string str;
       cin>>str;
       char last=str[0];
       if(last=='W')
       {
           ans++;
           b=1;
           p++;
       }
       else l++;
       int act=1;
       int it=0;
       for(int i=1;i<n;i++)
       {
            if(str[i]=='W')
            {
                p++;
                if(last=='W')
                {
                    act++;
                    ans+=2;
                }
                else
                {
                    ans++;
                    if(b)
                        v.pb(act);
                    last='W';
                    act=1;
                }
                b=1;
            }
            else
            {
                l++;
                if(last=='W')
                {
                    last='L';
                    act=1;
                }
                else
                {
                    act++;
                }
            }
       }
       sort(v.begin(),v.end());
       for(int i=0;i<v.size();i++)
       {
            if(v[i]<=k)
            {
                l-=v[i];
                k-=v[i];
                ans+=2*v[i]+1;
            }
       }
       //cout<<l<<" "<<p<<" "<<k<<endl;
       if(p>0)
            ans+=2*min(k,l);
       else ans+=max((int)0,2*min(k,l)-1);
       cout<<ans<<endl;
    }

    return 0;
}