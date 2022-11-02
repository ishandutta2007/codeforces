#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n;
    cin>>t;
    map <int,int> mapa;
    for(int j=0;j<t;j++)
    {
        mapa.clear();
        cin>>n;
        int tab[n];
        int pod=0;
        for(int i=0;i<n;i++) cin>>tab[i];
        for(int i=0;i<n;i++)
        {
            mapa[tab[i]]++;
            if(mapa[tab[i]]==1) pod++;
        }
        int maxi=0;
        for(int i=0;i<n;i++) maxi=max(maxi,mapa[tab[i]]);
        if(maxi==pod) cout<<pod-1<<endl;
        else cout<<min(maxi,pod)<<endl;

    }
    return 0;
}