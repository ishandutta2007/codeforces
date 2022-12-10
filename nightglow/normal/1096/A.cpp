#include<cstdio>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    for (;T--;)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d %d\n",l,l*2);
    }
}