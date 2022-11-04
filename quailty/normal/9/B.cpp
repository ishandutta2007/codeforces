#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db eps=1e-4;
db x[105];
int main()
{
    int n,v[2];
    scanf("%d%d%d",&n,&v[0],&v[1]);
    for(int i=1;i<=n;i++)
        scanf("%lf",&x[i]);
    db ux,uy;
    scanf("%lf%lf",&ux,&uy);
    int t=2;
    for(int i=2;i<=n;i++)
    {
        if(x[i]/v[0]+sqrt((ux-x[i])*(ux-x[i])+uy*uy)/v[1]
           <x[t]/v[0]+sqrt((ux-x[t])*(ux-x[t])+uy*uy)/v[1]-eps)t=i;
        else if(x[i]/v[0]+sqrt((ux-x[i])*(ux-x[i])+uy*uy)/v[1]
           <x[t]/v[0]+sqrt((ux-x[t])*(ux-x[t])+uy*uy)/v[1]+eps
           && sqrt((ux-x[i])*(ux-x[i])+uy*uy)<sqrt((ux-x[t])*(ux-x[t])+uy*uy)/v[1]-eps)t=i;

    }
    printf("%d\n",t);
    return 0;
}