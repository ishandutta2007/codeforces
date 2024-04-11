#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%i %i",&n,&k);
    int koliko=n/(k*2+1)+1;
    //printf("%i\n",koliko);
    int ostatak=n%(k*2+1);
    //printf("%i\n",ostatak);
    if(ostatak==0)
    {
        koliko--;
        ostatak=2*k;
    }
    ostatak--;
    ostatak=min(k,ostatak);
    ostatak++;
    if(ostatak==0)
    {
        ostatak++;
    }
    //printf("Mesta:%i\n",ostatak);
    printf("%i\n",koliko);
    for(int i=0;i<koliko;i++)
    {
        printf("%i ",ostatak);
        ostatak+=k*2+1;
    }
    printf("\n");
    return 0;
}