#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll ile[111111];
ll cum[111111];

int dig(int k)
{
    int res=0;
    while(k>0)
    {
        k/=10;
        res++;
    }
    return res;
}

int kty(int n,int k)
{
    vector<int> a;
    while(n)
    {
        a.push_back(n%10);
        n/=10;
    }
    reverse(a.begin(),a.end());
    return a[k-1];
}

int main()
{
    ile[0]=0;
    ile[1]=1;
    cum[1]=1;
    for(int i=2;i<111111;i++)
    {
        ile[i]=ile[i-1]+dig(i);
    }
    int q; cin>>q;
    bool ok = true;
    while(q--)
    {
        int k; cin>>k;
        int akt=1;
        while(1)
        {
            if(k<=ile[akt]) break;
            else
            {
                k-=ile[akt];
                akt++;
            }
        }
        for(int i=1;i<=akt;i++)
        {
            if(dig(i)<k)
            {
                k-=dig(i);
            }
            else
            {
                //cout<<"XD"<<i<<" "<<k<<endl;
                cout<<kty(i,k)<<endl;
                break;
            }
        }
        //ok = false;
    }
    return 0;
}