#include <iostream>
#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

ll akt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin>>q;
    while(q--)
    {
        ll n; cin>>n;
        vector<ll> wsp;
        akt=n;
        while(akt)
        {
            wsp.push_back(akt%3);
            akt/=3;
        }
        wsp.push_back(0);
        for(int i=0;i<wsp.size();i++)
        {
            if(wsp[i]==3)
            {
                wsp[i+1]++;
                wsp[i]=0;
                continue;
            }
            if(wsp[i]==2)
            {
                wsp[i+1]++;
                for(int j=0;j<=i;j++) wsp[j]=0;
            }
        }
        ll res=0;
        ll mn=1;
        for(int i=0;i<wsp.size();i++)
        {
            res+=mn*wsp[i];
            mn*=3;
        }
        cout<<res<<endl;
    }
    return 0;
}