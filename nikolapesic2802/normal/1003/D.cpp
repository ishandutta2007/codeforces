#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,q;
    scanf("%i %i",&n,&q);
    map<int,int> mapa;
    int a=1;
    int cnt=0;
    while(a<pow(10,9))
    {
        mapa[a]=cnt;
        //printf("%i- %i\n",a,cnt);
        a*=2;
        cnt++;
    }
    int novcici[30]={};
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%i",&x);
        novcici[mapa[x]]++;
    }
    for(int i=0;i<q;i++)
    {
        int broj;
        scanf("%i",&broj);
        int k=0;
        for(int j=29;j>=0;j--)
        {
            int tr=pow(2,j);
            int koliko=broj/tr;
            int dostupno=min(koliko,novcici[j]);
            k+=dostupno;
            broj-=dostupno*tr;
        }
        if(broj==0)
        {
            printf("%i\n",k);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}