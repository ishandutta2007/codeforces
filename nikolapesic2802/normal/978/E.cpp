#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,w;
    scanf("%i %i",&n,&w);
    int minn=0,maxx=0;
    int tr=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        tr+=a;
        minn=min(tr,minn);
        maxx=max(tr,maxx);
    }
    //printf("%i %i\n",minn,maxx);
    printf("%i\n",max(w+minn-maxx+1,0));
    return 0;
}