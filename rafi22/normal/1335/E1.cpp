#include <bits/stdc++.h>

using namespace std;

int pref[100007][201];
int pos[201][100007];


int main()
{
    int t;
    cin>>t;
    map <int,int> mapa;
    for(int i=0;i<t;i++)
    {
        mapa.clear();
        int n;
        cin>>n;
        int tab[n];
        int ans=0;
        for(int j=1;j<=n;j++) cin>>tab[j];
        for(int j=1;j<=n;j++)
        {
            for(int l=1;l<=200;l++)
            {
                pref[j][l]=pref[j-1][l];
            }
            pref[j][tab[j]]++;
            pos[tab[j]][pref[j][tab[j]]]=j;
        }

        int og;
        if(n%2==0) og=n/2;
        else og=n/2+1;
        for(int j=n;j>0;j--)
        {
            mapa[tab[j]]++;
            if(pos[tab[j]][mapa[tab[j]]]>0&&pos[tab[j]][mapa[tab[j]]]<j)
            {
                //cout<<j<<" "<<mapa[tab[j]]<<" "<<pos[tab[j]][mapa[tab[j]]]<<endl;
                int maxi=0;
                for(int l=1;l<=200;l++)
                {
                    maxi=max(maxi,pref[j-1][l]-pref[pos[tab[j]][mapa[tab[j]]]][l]);
                    //cout<<pref[j-1][l]-pref[pos[tab[j]][mapa[tab[j]]]][l]<<endl;
                }
                ans=max(2*mapa[tab[j]]+maxi,ans);
            }

        }
        if(ans==0) cout<<1<<endl;
        else cout<<ans<<endl;

    }
    return 0;
}