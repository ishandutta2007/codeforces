#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    for(int i=0;i<n;i++)
    {
        int duzina=0,pocetak;
        for(int j=0;j<m;j++)
        {
            char c;
            scanf(" %c ",&c);
            if(c=='B')
            {
                //printf("Nasao na %i %i\n",i,j);
                pocetak=j;
                duzina++;
            }
        }
        if(duzina>0)
        {
            //printf("%i\n",pocetak);
            printf("%i %i\n",i+duzina/2+1,pocetak-duzina/2+1);
            return 0;
        }
    }
    return 0;
}