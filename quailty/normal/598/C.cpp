#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long double db;
const db PI=acos(-1.0);
struct Point
{
    int x,y,id;
    db arc;
    bool operator < (const Point &t)const
    {
        return arc<t.arc;
    }
};
vector<Point>v;
int main()
{
    int n;
    scanf("%d",&n);
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&v[i].x,&v[i].y);
        v[i].id=i+1;
        v[i].arc=atan2(v[i].y,v[i].x);
    }
    sort(v.begin(),v.end());
    v.push_back(v[0]);
    v[n].arc+=2*PI;
    db Min=1e8;
    int loc=0;
    for(int i=1;i<=n;i++)
        if(v[i].arc-v[i-1].arc<Min)
        {
            Min=v[i].arc-v[i-1].arc;
            loc=i;
        }
    printf("%d %d\n",v[loc-1].id,v[loc].id);
    return 0;
}