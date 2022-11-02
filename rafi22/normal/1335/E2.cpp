#include <bits/stdc++.h>

using namespace std;

int pref[200007][201];
vector<int> pos[201];
int mapa[207];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<=200;j++) mapa[j]=0;
        for(int j=0;j<=200;j++) pos[j].clear();
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
            pos[tab[j]].push_back(j);
            //cout<<tab[j]<<" "<<j<<endl;
        }
        for(int j=n;j>0;j--)
        {
            mapa[tab[j]]++;
            //cout<<pos[tab[j]][mapa[tab[j]]-1]<<endl;
            if(pos[tab[j]][mapa[tab[j]]-1]>0&&pos[tab[j]][mapa[tab[j]]-1]<j)
            {
                //cout<<j<<" "<<mapa[tab[j]]<<" "<<pos[tab[j]][mapa[tab[j]]]<<endl;
                int maxi=0;
                for(int l=1;l<=200;l++)
                {
                    maxi=max(maxi,pref[j-1][l]-pref[pos[tab[j]][mapa[tab[j]]-1]][l]);
                    //cout<<pref[j-1][l]-pref[pos[tab[j]][mapa[tab[j]]]][l]<<endl;
                }
                ans=max(2*mapa[tab[j]]+maxi,ans);
            }

        }
        if(ans==0) cout<<1<<'\n';
        else cout<<ans<<'\n';

    }
    return 0;
}