#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
map<pair<int, int>,int> first1;
map<int ,int> first[11];
ll n,k;
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll res=0;
    cin>>n>>k;
    ll a[n],max1=0,min1=10;
    for(int i=0;i<n;i++)
       {
         cin>>a[i];
         ll j=a[i],t=0;
         ll f=1;
         while(j){t++;j/=10;f*=10;f%=k;}
        ll q=((a[i]%k)*(f%k))%k;
		       if((q+a[i])%k==0)
			      res--;
 
          first[t][(k-a[i]%k)%k ]++;
       }
 
       for(int i=0;i<n;i++)
       { ll g1=1;
 
         for(int j=1;j<=10;j++)
         {
              g1*=10;
              ll g=g1%k;
                //cout<<a[i]<<" "<<j<<" "<<g<<"\n";
                g*=(a[i]%k);
                g%=k;
                if(first[j].find(g)!=first[j].end())
			       res+=first[j][g];
 
 
 
         }
       }
       cout<<res;
}