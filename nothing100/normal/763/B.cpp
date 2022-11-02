#include<bits/stdc++.h>
#define MAXN 200010
#define inf 1000000000
#define LL long long
using namespace std;
struct point{
    int x,y;
}p[500010][2];
int n;
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d%d%d%d",&p[i][0].x,&p[i][0].y,&p[i][1].x,&p[i][1].y);
    printf("YES\n");
    for (int i=0;i<n;i++){
        printf("%d\n",2*(p[i][0].x&1)+(p[i][0].y&1)+1);
    }
}