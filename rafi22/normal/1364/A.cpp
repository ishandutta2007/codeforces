#include <bits/stdc++.h>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,act=0,maxi=-1,niema=0;
        cin>>n>>x;
        int tab[n+7];
        int last[x+7];
        last[0]=-1;
        for(int i=1;i<=n;i++)
        {
            cin>>tab[i];
        }
        for(int i=1;i<x;i++)
        {
            last[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            act+=tab[i];
            act%=x;
            //cout<<(x-tab[i])%x<<endl;
            //cout<<last[x-tab[i]]<<endl;
            if(last[(x-act)%x]!=-1) maxi=max(maxi,i-last[(x-act)%x]);
            //cout<<maxi<<endl;
            if(act!=0&&last[0]==-1)
            {
                last[0]=i;
            }
        }
        for(int i=0;i<x;i++)
        {
           // cout<<last[i]<<" ";
        }
        //cout<<endl;
        cout<<maxi<<endl;
    }
    return 0;
}