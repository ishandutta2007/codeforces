#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    if(y==0)return 0*printf("No\n");
    if(y==1)return 0*printf("%s\n",(x==0 ? "Yes" : "No"));
    return 0*printf("%s\n",(x>=y-1 && (x+y)%2==1 ? "Yes" : "No"));
}