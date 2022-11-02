#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int l=0;l<t;l++)
    {
        int n,maxi=0,act=0;
        cin>>n;
        int tab[n+7];
        int DP[n+7];
        for(int j=1;j<=n;j++)
        {
            cin>>tab[j];
            DP[j]=1;
        }
        for(int i=n;i>0;i--)
        {
            maxi=max(maxi,DP[i]);
            for(int j=1;j<=sqrt(i);j++)
            {
                if(i%j==0)
                {
                    if(tab[i/j]<tab[i]) DP[i/j]=max(DP[i/j],DP[i]+1);
                    if(tab[i/(i/j)]<tab[i]) DP[i/(i/j)]=max(DP[i/(i/j)],DP[i]+1);
                }
            }
        }
        cout<<maxi<<endl;

    }
    return 0;
}