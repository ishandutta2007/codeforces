#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;

int p[1000],l[1000],t[1000];
int prang,lrang;
int pw[1000],lw[1000],pr[1000];
int i,j;
int n,m;
int totaluang;
int maxi;
int banyaksatu;
int keliling;
int banyaktotal;
int roll;

int main()
{
    scanf("%d",&n);
    for (i=0;i<n;i++)
        scanf("%d %d %d",&p[i],&l[i],&t[i]);
    scanf("%d",&m);
    for (i=0;i<m;i++)
        scanf("%d %d %d",&pw[i],&lw[i],&pr[i]);
    for (i=0;i<n;i++)
    {
        maxi=2000000000;
        for (j=0;j<m;j++)
        {
            keliling=2*(p[i]+l[i]);
            if (pw[j]>=t[i])
            {
                banyaksatu=pw[j]/t[i];
                banyaktotal=banyaksatu*lw[j];
                if (keliling%banyaktotal==0)
                {
                    roll=keliling/banyaktotal;
                }
                else
                    roll=(keliling/banyaktotal)+1;
                if (roll*pr[j]<=maxi)
                    maxi=roll*pr[j];
                    
            }
            
        }
        totaluang+=maxi;
    }
    printf("%d\n",totaluang);
    
}