#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("a.out","w",stdout);
    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%d %d %d",&a,&b,&c);
    e=0;
    for(x=0;x<=c/b;x++)
    {
        if(x*b<=a)continue;
        if(e!=0)printf(" ");
        printf("%d",x*b-a);
        e++;
    }
    if(e==0)cout<<-1;
    cout<<endl;
}