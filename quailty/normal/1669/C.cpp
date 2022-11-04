#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,ty[2]={0,0};
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            ty[i&1]|=1<<(a&1);
        }
        printf("%s\n",(ty[0]<3 && ty[1]<3 ? "YES" : "NO"));
    }
    return 0;
}