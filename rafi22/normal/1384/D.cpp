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
        int bit[35];
        for(int i=0;i<35;i++) bit[i]=0;
        int n,a;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            int it=0;
            while(a>0)
            {
                if(a%2) bit[it]++;
                a/=2;
                it++;
            }
        }
        bool res=0,t=0;
        for(int i=33;i>=0;i--)
        {
            if(bit[i]%2!=0)
            {
                t=1;
                if(((bit[i]-1)/2)%2==0) break;
                if(n%2!=0)
                {
                    res=1;
                }
                break;
            }
        }
        if(!t) cout<<"DRAW"<<endl;
        else if(!res) cout<<"WIN"<<endl;
        else cout<<"LOSE"<<endl;
    }


    return 0;
}