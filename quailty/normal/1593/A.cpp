#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a[3];
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        for(int i=0;i<3;i++)
            printf("%d%c",max(0,max(a[(i+1)%3],a[(i+2)%3])+1-a[i])," \n"[i==2]);
    }
    return 0;
}