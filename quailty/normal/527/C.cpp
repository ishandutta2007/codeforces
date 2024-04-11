#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int lenx[200005],leny[200005];
set<int>hor,ver;
int main()
{
    int w,h,n;
    scanf("%d%d%d",&w,&h,&n);
    hor.insert(0);
    hor.insert(h);
    leny[0]++;
    leny[h]++;
    ver.insert(0);
    ver.insert(w);
    lenx[0]++;
    lenx[w]++;
    set<int>::iterator itr,itr1,itr2;
    char op[3];
    int dis;
    int maxy=h,maxx=w;
    for(int i=1;i<=n;i++)
    {
        scanf("%s%d",op,&dis);
        if(op[0]=='H')
        {
            hor.insert(dis);
            itr=hor.find(dis);
            itr1=itr;
            itr2=itr;
            itr1--;
            itr2++;
            leny[*itr2-*itr1]--;
            leny[*itr2-*itr]++;
            leny[*itr-*itr1]++;
        }
        else
        {
            ver.insert(dis);
            itr=ver.find(dis);
            itr1=itr;
            itr2=itr;
            itr1--;
            itr2++;
            lenx[*itr2-*itr1]--;
            lenx[*itr2-*itr]++;
            lenx[*itr-*itr1]++;
        }
        while(!leny[maxy])maxy--;
        while(!lenx[maxx])maxx--;
        printf("%I64d\n",1LL*maxx*maxy);
    }
    return 0;
}