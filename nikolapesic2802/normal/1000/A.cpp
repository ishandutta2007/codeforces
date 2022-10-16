#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    int broj_m=0,broj_s[4]={},broj_l[4]={};
    int broj_m_2=0,broj_s_2[4]={},broj_l_2[4]={};
    for(int i=0;i<n;i++)
    {
        char niz[5];
        scanf("%s",niz);
        string s=niz;
        if(niz[0]=='M')
        {
            broj_m++;
            continue;
        }
        int broj_x=0;
        int x=0;
        while(niz[x]=='X')
        {
            broj_x++;
            x++;
        }
        if(niz[x]=='S')
        {
            broj_s[broj_x]++;
        }
        else
        {
            broj_l[broj_x]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        char niz[5];
        scanf("%s",niz);
        if(niz[0]=='M')
        {
            broj_m_2++;
            continue;
        }
        int broj_x=0;
        int x=0;
        while(niz[x]=='X')
        {
            broj_x++;
            x++;
        }
        if(niz[x]=='S')
        {
            broj_s_2[broj_x]++;
        }
        else
        {
            broj_l_2[broj_x]++;
        }
    }
    int res=0;
    res+=abs(broj_m-broj_m_2);
    for(int i=0;i<4;i++)
    {
        res+=abs(broj_s[i]-broj_s_2[i]);
        res+=abs(broj_l[i]-broj_l_2[i]);
    }
    printf("%i\n",res/2);
    return 0;
}