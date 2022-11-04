#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db eps=1e-9;
int main()
{
    db vp,vd,t,f,c;
    scanf("%lf%lf%lf%lf%lf",&vp,&vd,&t,&f,&c);
    if(vp>vd-eps)return 0*printf("0");
    db now=t*vp;
    int res=0;
    while(now<c-eps)
    {
        db nxt=now/(vd-vp);
        if(nxt>(c-now)/vp-eps)break;
        res++;
        now+=nxt*vp;
        now+=(now/vd+f)*vp;
    }
    return 0*printf("%d",res);
}