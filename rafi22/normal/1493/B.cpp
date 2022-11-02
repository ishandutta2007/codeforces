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
       // cout<<"xd"<<endl;
        int h,m,ah,am;
        cin>>h>>m;
        string s;
        cin>>s;
        ah=(s[0]-'0')*10+s[1]-'0';
        am=(s[3]-'0')*10+s[4]-'0';
        while(true)
        {
            int nh=0,nm=0;
            bool ok=1;
            if(ah%10==0||ah%10==1||ah%10==8) nm+=ah%10*10;
            else if(ah%10==2) nm+=5*10;
            else if(ah%10==5) nm+=2*10;
            else ok=0;

            if(ah/10==0||ah/10==1||ah/10==8) nm+=ah/10;
            else if(ah/10==2) nm+=5;
            else if(ah/10==5) nm+=2;
            else ok=0;

            if(am%10==0||am%10==1||am%10==8) nh+=am%10*10;
            else if(am%10==2) nh+=5*10;
            else if(am%10==5) nh+=2*10;
            else ok=0;

            if(am/10==0||am/10==1||am/10==8) nh+=am/10;
            else if(am/10==2) nh+=5;
            else if(am/10==5) nh+=2;
            else ok=0;

            if(ok&&nh<h&&nm<m)
            {
                if(ah/10==0) cout<<0;
                cout<<ah<<':';
                if(am/10==0) cout<<0;
                cout<<am<<endl;
                break;
            }
            if(am==m-1)
            {
                ah++;
                ah%=h;
                am=0;
            }
            else am++;
        }
    }

    return 0;
}