#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p[3]={0,1,2};
    scanf("%d",&n);
    bool isok=1;
    while(n--)
    {
        int a;
        scanf("%d",&a);
        a--;
        if(p[0]==p[0]+p[1]-a)
            swap(p[0],p[2]);
        else if(p[1]==p[0]+p[1]-a)
            swap(p[1],p[2]);
        else isok=0;
    }
    printf("%s\n",(isok ? "YES" : "NO"));
    return 0;
}