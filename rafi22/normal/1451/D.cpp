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

int ile1[27],ile2[27];

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
        int d,k;
        cin>>d>>k;
        bool winer=0,mini=inf;
        int l=0,p=d/k+10,sr,ans=0;
        while(l<=p)
        {
            sr=(l+p)/2;
            if(sr*k*sr*k<=d*d)
            {
                ans=sr*k;
                l=sr+1;
            }
            else p=sr-1;
        }
        int mxi=0;
        for(int i=0;i<=d;i+=k)
        {
            while(ans*ans+i*i>d*d) ans-=k;
            int x=ans/k+i/k;
            mxi=max(mxi,x);
        }
        if(mxi%2) cout<<"Ashish"<<endl;
        else cout<<"Utkarsh"<<endl;
    }

    return 0;
}