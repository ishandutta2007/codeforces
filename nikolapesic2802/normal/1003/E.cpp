#include <bits/stdc++.h>

using namespace std;
int stigao;
int maxx;
int kk;
clock_t begint,endt;
void ispisi(int dubina,int prosli)
{
    stigao++;
    if(stigao<=maxx)
    {
        /*double proteklo=((double)(endt=clock() - begint) / CLOCKS_PER_SEC);
        if(maxx>10000)
        {
            printf("%f\n",proteklo);
        }*/
        printf("%i %i\n",prosli,stigao);
        if(dubina==1)
        {
            return;
        }
        int s=stigao;
        int d=dubina;
        for(int i=0;i<kk-1;i++)
        {
            ispisi(d-1,s);
        }
    }
}
void construct(int n,int d,int k)
{
    for(int i=0;i<d;i++)
    {
        printf("%i %i\n",i+1,i+2);
    }
    /*if(maxx>10000)
    {
        return;
    }*/
    n-=d+1;
    stigao=d+1;
    //printf("Treba jos: %i %i\n",n,stigao);
    for(int i=2;i<=d;i++)
    {
        //printf("%i %i  lol\n",i,min(i-1,d-i+1));
        if(stigao<=maxx)
        {
        int dd=min(i-1,d-i+1);
        for(int j=0;j<k-2;j++)
        {
            ispisi(dd,i);
        }
        }
    }
}
int main()
{
    begint=clock();
    int n,d,k;
    scanf("%i %i %i",&n,&d,&k);
    maxx=n;
    kk=k;
    if(d==1)
    {
        if(n==2)
        {
            printf("YES\n1 2\n");
            return 0;
        }
    }
    if(d>=n)
    {
        printf("NO\n");
        return 0;
    }
    if(d>1&&k==1)
    {
        printf("NO\n");
        return 0;
    }
    //printf("stigap");
    long long max_broj=d+1,nn=n;
    int tr=d-1;
    long long tr2=(long long)(k-2);
    while(tr>0)
    {
        max_broj+=(long long)tr*tr2;
        if(max_broj>=nn)
        {
            double proteklo=((double)(endt=clock() - begint) / CLOCKS_PER_SEC);
            /*if(nn>10000)
            {
                printf("%f\n",proteklo);
            }*/
            printf("YES\n");
            construct(n,d,k);
            return 0;
        }
        tr2=(long long)tr2*(long long)(k-1);
        tr-=2;
    }
    printf("NO\n");
    return 0;
}