#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <deque>
#include <set>
using namespace std;

int n,i;
int k,b;
set <pair<int,int> > ada;
pair <int,int> ubah;

int main()
{
    scanf("%d",&n);
    for (i=0;i<n;++i)
    {
        scanf("%d %d",&k,&b);
        if (k!=0)
        {
            if (b==0)
            {
                ubah.first=1;
                ubah.second=0;
            }
            else
            {
                ubah.first=k/__gcd(k,b);
                ubah.second=b/__gcd(k,b);
            }
            if (ubah.first<0)
            {
                ubah.first=-ubah.first;
                ubah.second=-ubah.second;
            }
            ada.insert(ubah);
        }
    }
    printf("%d\n",ada.size());
}