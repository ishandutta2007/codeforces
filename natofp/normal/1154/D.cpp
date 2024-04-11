#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b; cin>>n>>b>>a;
    int akta=a;
    int aktb=b;
    int * t = new int[n];
    for(int i=0;i<n;i++) cin>>t[i];
    for(int i=0;i<n;i++)
    {
        if(akta==0 && aktb==0) {cout<<i; return 0;}
        if(t[i]==1)
        {
            if(akta==a)
            {
                akta--; continue;
            }
            else if(aktb>0)
            {
                akta++;
                aktb--;
                continue;
            }
            else
            {
                akta--; continue;
            }
        }
        else if(t[i]==0)
        {
            if(akta>0)
            {
                akta--; continue;
            }
            else
            {
                aktb--; continue;
            }
        }
    }
    cout<<n<<endl;
    return 0;
}