#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int l,r,a,z;
    scanf("%d%d%d",&l,&r,&a);
    if(l<r)
    {
        z=(l+min(r-l,a))*2;
        if(r-l<a)
        {
            a=a-(r-l);
            a=a/2*2;
            z+=a;
        }
        printf("%d",z);
    }
    else
    {
       z=(r+min(l-r,a))*2;
       if(l-r<a)
        {
            a=a-(l-r);
            a=a/2*2;
            z+=a;
        }
        printf("%d",z);
    }

    return 0;
}