#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

struct x
{
    int angka,banyak;

};

bool operator <(x a, x b)
{
    return a.banyak<b.banyak;
}
map <int,int> posi;
priority_queue <x> temp;
vector <x> banyak;
int i,n;
int tmp;
x tmp2;
x a,b,c;
vector <vector <int> > sol;
vector <int> soltemp;
int main()
{
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        if (posi.find(tmp)==posi.end())
        {
            posi[tmp]=banyak.size();
            tmp2.angka=tmp;
            tmp2.banyak=1;
            banyak.push_back(tmp2);
        }
        else
        {
            banyak[posi[tmp]].banyak++;
        }
    }
    for (i=0;i<banyak.size();i++)
        temp.push(banyak[i]);
    while (temp.size()>=3)
    {
        a=temp.top();
        temp.pop();
        b=temp.top();
        temp.pop();
        c=temp.top();
        temp.pop();
        soltemp.push_back(a.angka);
        soltemp.push_back(b.angka);
        soltemp.push_back(c.angka);
        sort(soltemp.begin(),soltemp.end());
        sol.push_back(soltemp);
        soltemp.clear();
        a.banyak--;
        b.banyak--;
        c.banyak--;
        if (a.banyak>0)
            temp.push(a);
        if (b.banyak>0)
            temp.push(b);
        if (c.banyak>0)
            temp.push(c);
    }
    printf("%d\n",sol.size());
    for (i=0;i<sol.size();i++)
        printf("%d %d %d\n",sol[i][2],sol[i][1],sol[i][0]);
}