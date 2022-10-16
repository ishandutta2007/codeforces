#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;



ll tab[5555];

ll ans(int a,int b)
{
    if(a==b && tab[a]==0) return 0;
    ll w1=0,w2=0;
    w1=b-a+1;
    ll naj=1e9+5;
    for(int i=a;i<=b;i++) naj=min(naj,tab[i]);
    for(int i=a;i<=b;i++)
    {
        tab[i]-=naj;
    }
    w2+=naj;
    int x=-1,y=-1;
    int i=a;
    while(i<=b)
    {
        while(i<=b && tab[i]==0) i++;
        x=i;
        while(i<=b && tab[i]!=0) i++;
        y=i;
        if(x<=b)
        {
            w2+=ans(x,y-1);
        }
    }


    return min(w1,w2);
}

int main()
{
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>tab[i];
    cout<<ans(0,n-1);


    return 0;
}