#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,x,y;
    scanf("%i %i %i",&n,&x,&y);
    char niz[n];
    scanf("%s",niz);
    string s=niz;
    //cout << s << endl;
    int broj_0=0,broj_1=0;
    if(niz[0]=='0')
    {
        broj_0++;
    }
    else
    {
        broj_1++;
    }
    for(int i=1;i<n;i++)
    {
        if(niz[i]!=niz[i-1])
        {
            if(niz[i]=='0')
            {
                broj_0++;
            }
            else
            {
                broj_1++;
            }
        }
    }
    long long cena=0;
    if(broj_0>0)
    {
    if(x<y)
    {
        cena+=(long long)(broj_0-1)*(long long)x;
        broj_0=1;
    }
    cena+=(long long)broj_0*(long long)y;
    //printf("%i %i\n",broj_0,broj_1);
    }
    printf("%I64d\n",cena);
    return 0;
}