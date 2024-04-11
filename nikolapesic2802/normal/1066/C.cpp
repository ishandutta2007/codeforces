#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int q;
    scanf("%i",&q);
    int pocetak=-1,kraj=1;
    int m=2*1e5+1;
    vector<int> poz(m);
    for(int i=0;i<q;i++)
    {
        char c;
        scanf(" %c",&c);
        int n;
        scanf("%i",&n);
        if(i==0)
        {
            poz[n]=0;
            continue;
        }
        if(c=='L')
        {
            poz[n]=pocetak;
            pocetak--;
        }
        if(c=='R')
        {
            poz[n]=kraj;
            kraj++;
        }
        if(c=='?')
        {
            //printf("Usao na %i\n",i);
            int p=poz[n];
            int d1=min(abs(p-pocetak)-1,abs(kraj-p)-1);
            printf("%i\n",d1);
        }
    }
    return 0;
}