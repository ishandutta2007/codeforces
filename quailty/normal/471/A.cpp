#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int c[6];
    for(int i=0;i<6;i++)
        scanf("%d",&c[i]);
    sort(c,c+6);
    int p=-1;
    for(int i=0;i<3;i++)
        if(c[i]==c[i+3])p=i;
    if(p==-1)printf("Alien");
    else printf("%s",(c[(p+4)%6]==c[(p+5)%6] ? "Elephant" : "Bear"));
    return 0;
}