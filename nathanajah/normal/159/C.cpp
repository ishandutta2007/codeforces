#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
using namespace std;

int k;
string s;
int n,i,j;
int panjang;
int q;
char tanya;
int banyak[30][3000];
bool part[3000][100];
int perhuruf[30];


void upd()
{
    int i=0;
    int ind=tanya-'a';
    int now=0;
    int posi=0;
    int sisa;
    while (now<q)
    {
//        printf("%d\n",now);
        now+=banyak[ind][posi];
        ++posi;
    }
    --posi;
    now-=banyak[ind][posi];
    sisa=q-now;
//    printf("%d %d %d\n",posi,sisa,now);
    i=0;
    while (sisa>0)
    {
//       printf("%d %d\n",i,sisa);
        if (s[i]==tanya)
            if (!part[posi][i])
                --sisa;
        ++i;
    }
    --i;
    part[posi][i]=true;
    --banyak[ind][posi];
}

int main()
{
    scanf("%d",&k);
    cin >> s;
    panjang=s.length();
    for (i=0;i<panjang;++i)
        ++perhuruf[s[i]-'a'];
    for (i=0;i<k;++i)
    {
        for (j=0;j<30;++j)
            banyak[j][i]=perhuruf[j];
    }
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d %c",&q,&tanya);
        upd();
    }
    for (j=0;j<k;j++)
        for (i=0;i<panjang;i++)
            if (!part[j][i])
                printf("%c",s[i]);
    printf("\n");
}