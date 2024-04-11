#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int l=0;l<t;l++)
    {
        int n,k;
        cin>>n>>k;
        int tab[n];
        int poss[2*k+7];
        for(int i=0;i<=2*k;i++) poss[i]=0;
        for(int i=0;i<n;i++) cin>>tab[i];
        map<int,int> mapa;
        vector <int> suma;
       // vector <pair<int,bool,int> > zdarzenie;
        for(int i=0;i<n/2;i++)
        {
           /* if(mapa[tab[i]+tab[n-i-1]]==0)
            {
                suma.push_back(tab[i]+tab[n-i-1]);
            }*/
            poss[min(tab[i],tab[n-i-1])+1]++;
            poss[max(tab[i],tab[n-i-1])+k+1]--;
            //zdarzenie.push_back(make_pair(min(tab[i],tab[n-i-1])+1,0));
            //zdarzenie.push_back(make_pair(max(tab[i]tab[n-i-1])+k,1));
            /*maxi.push_back(max(tab[i],tab[n-i-1]));
            mini.push_back(min(tab[i],tab[n-i-1]));*/
            mapa[tab[i]+tab[n-i-1]]++;
        }
      //  sort(zdarzenie.begin(),zdarzenie.end());
        //sort(suma.begin(),suma.end());
       // cout<<suma.size()<<endl;
        int act=0,ans=1000000007;
        for(int i=2;i<=2*k;i++)
        {
            act+=poss[i];
            ans=min(ans,act+2*(n/2-act)-mapa[i]);

        }
        cout<<ans<<endl;

    }
    return 0;
}