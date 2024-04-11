#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int l[30],r[30];
int main()
{
    int d,s;
    scanf("%d%d",&d,&s);
    int sl=0,sr=0;
    for(int i=0;i<d;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        sl+=l[i];
        sr+=r[i];
    }
    if(s<sl || s>sr)return 0*printf("NO");
    printf("YES\n");
    s-=sl;
    for(int i=0;i<d;i++)
    {
        if(s>=r[i]-l[i])printf("%d ",r[i]),s-=r[i]-l[i];
        else printf("%d ",l[i]+s),s=0;
    }
    return 0;
}