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
        int n,c;
        cin>>n;
        vector<pair<int,int>>Q1,Q2;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if((i+j)%2==0) Q1.pb({i,j});
                else Q2.pb({i,j});
            }
        }
        for(int i=0;i<n*n;i++)
        {
            cin>>c;
            if(c==1)
            {
                if(sz(Q2)>0)
                {
                    cout<<2<<" "<<Q2.back().st<<" "<<Q2.back().nd<<endl;
                    Q2.pop_back();
                }
                else
                {
                    cout<<3<<" "<<Q1.back().st<<" "<<Q1.back().nd<<endl;
                    Q1.pop_back();
                }
            }
            if(c==2)
            {
                if(sz(Q1)>0)
                {
                    cout<<1<<" "<<Q1.back().st<<" "<<Q1.back().nd<<endl;
                    Q1.pop_back();
                }
                else
                {
                    cout<<3<<" "<<Q2.back().st<<" "<<Q2.back().nd<<endl;
                    Q2.pop_back();
                }
            }
            if(c==3)
            {
                if(sz(Q1)>0)
                {
                    cout<<1<<" "<<Q1.back().st<<" "<<Q1.back().nd<<endl;
                    Q1.pop_back();
                }
                else
                {
                    cout<<2<<" "<<Q2.back().st<<" "<<Q2.back().nd<<endl;
                    Q2.pop_back();
                }
            }
        }
    }

    return 0;
}