#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int mod=1000000007;

long long int suma(unsigned long long int first,unsigned long long int last)
{
    unsigned long long int ile=(last-first)/2+1;
    unsigned long long int sumka=(first+last);
    if(sumka%2==0) sumka/=2;
    else ile/=2;
    sumka%=mod;
    ile%=mod;
    long long int wyn=(long long int)sumka*ile;
    wyn%=mod;
    return wyn;
}

long long int ile(long long int n)
{
    long long int akt=1;
    int poz=0;
    long long int res=0;
    long long int ostatniapar=0;
    long long int ostatnianiepar=-1;
    while(n>0)
    {
        //cout<<"XD"<<endl;
        poz++;
        if(poz==3) poz-=2;
        if(n-akt>=0)
        {
            n-=akt;
            if(poz==1)
            {
                long long int first=ostatnianiepar+2;
                long long int last=ostatnianiepar+2*akt;
                long long int wyn=suma(first,last);
                res+=wyn;
                res%=mod;
                ostatnianiepar=last;
            }
            else if(poz==2)
            {
                long long int first=ostatniapar+2;
                long long int last=ostatniapar+2*akt;
                long long int wyn=suma(first,last);
                res+=wyn;
                res%=mod;
                ostatniapar=last;
            }
        }
        else if(n-akt<0)
        {

            if(poz==1)
            {
                long long int first=ostatnianiepar+2;
                long long int last=ostatnianiepar+2*n;
                long long int wyn=suma(first,last);
                res+=wyn;
                res%=mod;
                ostatnianiepar=last;
            }
            else if(poz==2)
            {
                long long int first=ostatniapar+2;
                long long int last=ostatniapar+2*n;
                long long int wyn=suma(first,last);
                res+=wyn;
                res%=mod;
                ostatnianiepar=last;
            }
            n=0;
        }
        akt*=2;

    }
    return res;
}


int main()
{
    long long int l,r; cin>>l>>r;
    long long int res=ile(r)-ile(l-1);
    if(res<0) res+=mod;
    if(res>=mod) res-=mod;
    cout<<res;
    return 0;
}