#include <bits/stdc++.h>
using namespace std;
string s;
int n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>s;
        a=0;
        n=s.length();
        for (j=0;j<8;j++)
        {
            u=0;
            v=0;
            for (auto g : s)
            {
            if (g=='A')
            {
                if (j&1) u++; else u--;
            }
            else if (g=='B')
            {
                if (j&2) u++; else u--;
            }
            else if (g=='C')
            {
                if (j&4) u++; else u--;
            }
            v=min(u,v);
            }
            if ((u==0)and(v==0)) a=1;
        }
        if (a) cout<<"YES\n";
        else cout<<"NO\n";
    }
}