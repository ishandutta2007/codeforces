#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,h,a,b,k;
    scanf("%i %i %i %i %i",&n,&h,&a,&b,&k);
    for(int i=0;i<k;i++)
    {
        int x1,y1,x2,y2;
        scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
        int path=abs(x1-x2);
        if(path==0)
        {
            printf("%i\n",abs(y1-y2));
        }
        else
        {
            if(y1>b)
            {
                path+=y1-b;
                y1=b;
            }
            if(y1<a)
            {
                path+=a-y1;
                y1=a;
            }
            path+=abs(y1-y2);
            printf("%i\n",path);
        }
    }
    return 0;
}