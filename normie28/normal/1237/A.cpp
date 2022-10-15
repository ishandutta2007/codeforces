#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a=0,b,n,m,i,j;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (i=1;i<=n;i++)
    {
            cin>>m; b=m;
            if (m%2) 
            {a++;
            m/=2;
            if ((a%2)and(b>0)) {m++;}
            if ((a % 2==0) and (b < 0))
            {
                m--;
            }
            }
            else m/=2;
            cout<<m<<endl;
    }       
}