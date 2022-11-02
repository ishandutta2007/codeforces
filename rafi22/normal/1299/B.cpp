#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin>>n;
    int tab[n][2];
    for(int i=0;i<n;i++)
    {
        cin>>tab[i][0]>>tab[i][1];
    }
    if(n%2==0)
    {
        bool ok=1;
        for(int i=0;i<n/2;i++)
        {
            if(tab[i][0]-tab[(i+1)%n][0]!=tab[(n/2+(i+1))%n][0]-tab[n/2+i][0]||tab[i][1]-tab[(i+1)%n][1]!=tab[(n/2+(i+1))%n][1]-tab[n/2+i][1]) ok=0;
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}