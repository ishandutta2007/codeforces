#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;

struct lol
{
    string a,gol;
};
int r,n,i,j;
lol a[2000];
int x[2000];
string tmp;
int tm2;
int notworse;
int better;

bool cmp(lol a, lol b)
{
    return a.a<b.a;
}
int main()
{
    scanf("%d",&r);
    for (i=0;i<r;++i)
    {
        cin >> tmp >> tm2;
        for (j=0;j<n;++j)
            if (a[j].a==tmp)
            {
                x[j]=max(x[j],tm2);
                break;
            }
        if (j==n)
        {
            a[n].a=tmp;
            x[n]=tm2;
            ++n;
        }
    }
    for (i=0;i<n;++i)
    {
        better=0;
        for (j=0;j<n;++j)
            if (x[j]>x[i])
                ++better;
        if (100*better>50*n)
            a[i].gol="noob";
        else if (100*better>20*n)
            a[i].gol="random";
        else if (100*better>10*n)
            a[i].gol="average";
        else if (100*better>1*n)
            a[i].gol="hardcore";
        else
            a[i].gol="pro";
    }
    sort(a,a+n,cmp);
    printf("%d\n",n);
    for (i=0;i<n;++i)
        cout << a[i].a << " " << a[i].gol << "\n";
    
}