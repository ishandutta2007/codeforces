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
        map <long long,long long> ile;
        long long n,k,act=1000000007,last=0,ans=0;
        cin>>n>>k;
        long long tab[n];
        for(int i=0;i<n;i++)
        {
            cin>>tab[i];
            tab[i]=(k-tab[i]%k)%k;
        }
        sort(tab,tab+n);
        vector <long long> kol;
        for(int i=0;i<n;i++)
        {
            long long t=tab[i];
            if(tab[i]!=0)
                tab[i]+=ile[tab[i]]*k;
           // cout<<tab[i]<<endl;
            kol.push_back(tab[i]);
            ile[t]++;
        }
       // cout<<endl;
        sort(kol.begin(),kol.end());
        cout<<kol[n-1]+1-(kol[n-1]==0)<<endl;

    }
    return 0;
}