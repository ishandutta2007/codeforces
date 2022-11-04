#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int x;
    scanf("%d",&x);
    if(x<0)x=-x;
    int l=0,r=x;
    while(l<r)
    {
        int m=(l+r)>>1;
        if(1LL*m*(m+1)/2>=x)r=m;
        else l=m+1;
    }
    while(1LL*l*(l+1)/2%2!=x%2)l++;
    printf("%d\n",l);
    return 0;
}