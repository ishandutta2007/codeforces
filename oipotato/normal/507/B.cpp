#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int r,x1,y1,x2,y2;
    scanf("%d%d%d%d%d",&r,&x1,&y1,&x2,&y2);
    printf("%d\n",(int)ceil(sqrt((LL)(x1-x2)*(x1-x2)+(LL)(y1-y2)*(y1-y2))/2/r));
    return 0;
}