#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct kubus
{
    int s,ind;
};

vector <kubus> daftar[200000];
int sz[200000];
long long jumlah[200000];
long long maxi1[200000],maxi2[200000],nummax1[200000],nummax2[200000];
int i,j,k;
long long total;
long long maxi,one,two,type;
int n;
long long bangka;
kubus tmp;
int c,angka;
map <int,int> peta;
int banyak;

bool cmp(kubus x, kubus y)
{
    return x.s>y.s;
}
int main()
{
    memset(maxi1,-1,sizeof(maxi1));
    memset(maxi2,-1,sizeof(maxi2));
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d %d",&c,&tmp.s);
        if (peta.find(c)==peta.end())
        {
            peta[c]=banyak;
            ++banyak;
        }
        angka=peta[c];
        tmp.ind=i+1;
        jumlah[angka]+=tmp.s;
        daftar[angka].push_back(tmp);
        ++sz[angka];
    }
    for (i=0;i<banyak;i++)
    {        
        sort(daftar[i].begin(),daftar[i].end(),cmp);
        if (jumlah[i]>maxi1[sz[i]])
        {
            maxi2[sz[i]]=maxi1[sz[i]];
            nummax2[sz[i]]=nummax1[sz[i]];
            maxi1[sz[i]]=jumlah[i];
            nummax1[sz[i]]=i;
        }
        else if(jumlah[i]>maxi2[sz[i]])
        {
            maxi2[sz[i]]=jumlah[i];
            nummax2[sz[i]]=i;
        }
    }
    for (i=0;i<banyak;i++)
    {
        total=0;
        for (j=0;j<sz[i];j++)
        {
            total+=daftar[i][j].s;
            for (k=j;k<=j+2;k++)
            {
                if (maxi1[k]>=0)
                {
                    if (nummax1[k]==i)
                    {
                        if (maxi2[k]>=0)
                            if (total+maxi2[k]>maxi)
                            {
                                maxi=total+maxi2[k];
                                one=i;
                                two=nummax2[k];
                                type=k-j;
                                bangka=j+k+1;
                            }
                    }
                    else if(total+maxi1[k]>maxi)
                    {
                        maxi=total+maxi1[k];
                        one=i;
                        two=nummax1[k];
                        type=k-j;
                        bangka=j+k+1;
                    }
                }
            }
        }
    }
    printf("%I64d\n",maxi);
    printf("%I64d\n",bangka);
    if (type==1)
    {
        for (i=0;i<sz[one];++i)
        {
            if (i>0)
                printf(" ");
            printf("%d %d",daftar[one][i].ind,daftar[two][i].ind);
        }
        printf("\n");
    }
    else if (type==0)
    {
        printf("%d",daftar[one][sz[two]].ind);
        for (i=0;i<sz[two];++i)
            printf(" %d %d",daftar[two][i].ind,daftar[one][i].ind);
        printf("\n");
    }
    else
    {
        printf("%d",daftar[two][sz[one]].ind);
        for (i=0;i<sz[one];++i)
            printf(" %d %d",daftar[one][i].ind,daftar[two][i].ind);
        printf("\n");
    }
}