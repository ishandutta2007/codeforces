#include <bits/stdc++.h>
using namespace std;
map<int,int> m;
int a[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool postojix=false,postojiy=false,moze=false;
    int i,n,l,x,y,poz=0,pom1,pom2;
    cin >> n >> l >> x >> y;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        m[a[i]]=1;
        if(m[a[i]-x]>0)
            postojix=true;
        if(m[a[i]-y]>0)
            postojiy=true;
    }
    if(postojix && postojiy)
        cout << 0;
    else
    {
        if(postojix==true)
            cout << 1 << endl << y;
        else
        {
            if(postojiy==true)
                cout << 1 << endl << x;
            else
            {
                for(i=0;i<n;i++)
                {
                    if(a[i]+x<l)
                    {
                        pom1=a[i]+x;
                        if(m[pom1-y]>0 || m[pom1+y]>0)
                        {
                            poz=pom1;
                            moze=true;
                            break;
                        }
                    }
                    if(a[i]-x>0)
                    {
                        pom1=a[i]-x;
                        if(m[pom1-y]>0 || m[pom1+y]>0)
                        {
                            poz=pom1;
                            moze=true;
                            break;
                        }
                    }
                }
                if(moze==true)
                    cout << 1 << endl << poz;
                else
                    cout << 2 << endl << x << " " << y;
            }
        }
    }
}