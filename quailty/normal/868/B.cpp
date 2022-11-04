#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int h,m,s,t1,t2;
    scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);
    h%=12,t1%=12,t2%=12;
    int arc_s=43200/60*s;
    int arc_m=43200/3600*(m*60+s);
    int arc_h=h*3600+m*60+s;
    int arc_t1=43200/12*t1;
    int arc_t2=43200/12*t2;
    for(int i=arc_t1;;i=(i+1)%43200)
    {
        if(i==arc_t2)return 0*printf("YES\n");
        if(i==arc_s || i==arc_m || i==arc_h)break;
    }
    for(int i=arc_t1;;i=(i-1+43200)%43200)
    {
        if(i==arc_t2)return 0*printf("YES\n");
        if(i==arc_s || i==arc_m || i==arc_h)break;
    }
    return 0*printf("NO\n");
}