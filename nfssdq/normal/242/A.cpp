#include <iostream>
#include <cstdio>
#include <cstdlib>
#include<vector>
using namespace std;
vector<pair<int,int> >vv;
int main()
{
    //freopen("a.out","w",stdout);
    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    for(x=c;x<=a;x++)
    {
        for(y=d;y<=b;y++)
        {
            if(x>y)vv.push_back(make_pair(x,y));
        }
    }
    printf("%d\n",vv.size());
    for(x=0;x<vv.size();x++)printf("%d %d\n",vv[x].first,vv[x].second);
}