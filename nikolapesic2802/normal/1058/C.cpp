#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    char s[n+5];
    scanf("%s",s);
    int niz[n+1];
    for(int i=0;i<n;i++)
    {
        niz[i]=s[i]-'0';
    }
    for(int i=1;i<n;i++)
    {
        int suma=0;
        for(int j=0; j<i; j++)
        {
            suma+=niz[j];
        }
        //printf("SUMA: %i\n",suma);
        //bool test=true;
        int tr=suma;
        for(int j=i;j<n;j++)
        {
            if(tr==0&&niz[j]!=0)
            {
                tr=suma;
            }
            if(tr<0)
            {
                break;
            }
            tr-=niz[j];
            //printf("%i\n",tr);
        }
        if(tr==0)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}