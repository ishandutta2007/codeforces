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

int querry(int x)
{
    cout<<"? "<<x+1<<endl;
    int y;
    cin>>y;
    return y;
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
        int n,k;
        cin>>n>>k;
        int p=0,a=1;
        while(true)
        {
            if(querry(p)>k)
            {
                while(true)
                {
                    if(p==0) p=n-1;
                    else p--;
                    if(querry(p)==k)
                    {
                        cout<<"! "<<p+1<<endl;
                        return 0;
                    }
                }
            }
            p=(p+a)%n;
            a++;
        }
    }

    return 0;
}