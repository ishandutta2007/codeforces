#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        long long n,res=0,maxi;
        cin>>n;
        long long tab[n+1];
        for(int j=1;j<=n;j++) cin>>tab[j];
        bool last;
        if(tab[1]>0) last=1;
        else last=0;
        maxi=tab[1];
        for(int j=2;j<=n;j++)
        {
            if(tab[j]>0)
            {
                if(!last)
                {
                    last=1;
                    res+=maxi;
                    maxi=tab[j];
                }
                else maxi=max(maxi,tab[j]);
            }
            else
            {
                if(last)
                {
                    last=0;
                    res+=maxi;
                    maxi=tab[j];
                }
                else
                    maxi=max(maxi,tab[j]);
            }
        }
        res+=maxi;
        cout<<res<<endl;


    }
    return 0;
}