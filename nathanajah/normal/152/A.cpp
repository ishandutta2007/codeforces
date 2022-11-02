#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <set>
#include <queue>
using namespace std;

int n,m;
int i,j,k;
char c[300][300];
int nummin;
bool best[300];
bool bess;
int banyak;

int main()
{
    scanf("%d %d",&n,&m);
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
            cin >> c[i][j];
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
        {
            bess=true;
            for (k=0;k<n;k++)
                bess=bess&&(c[i][j]>=c[k][j]);
            if (bess)
                best[i]=true;
        }
    for (i=0;i<n;i++)
        if (best[i])
            banyak++;
    cout << banyak << "\n";
                
}