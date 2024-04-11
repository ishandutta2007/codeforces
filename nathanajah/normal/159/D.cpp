#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
using namespace std;

string s;
int palin[2010][2010];
int i,j;
long long banyak[3000];
long long ret;
int n;

int cekpalin(int x, int y)
{
    int &ret=palin[x][y];
    if (ret>=0)
        return ret;
    if (x>=y)
        ret=1;
    else if (s[x]==s[y])
        ret=cekpalin(x+1,y-1);
    else
        ret=0;
    return ret;
}
int main()
{
    memset(palin,-1,sizeof(palin));
    cin >> s;
    n=s.length();
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            palin[i][j]=cekpalin(i,j);
    for (j=0;j<n;j++)
    {
        if (j>0)
            banyak[j]=banyak[j-1];
        for (i=0;i<=j;i++)
            if (palin[i][j]==1)
                ++banyak[j];
    }
    for (i=1;i<n;i++)
        for (j=i;j<n;j++)
            if (palin[i][j]==1)
                ret+=banyak[i-1];
    cout << ret << "\n";
}