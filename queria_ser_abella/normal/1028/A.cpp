#include <bits/stdc++.h>
using namespace std;

char str[333][333];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf(" %s",str[i]);
    int sx = 0, qx = 0, sy = 0, qy = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(str[i][j] == 'B'){
                qx++;
                qy++;
                sx += i;
                sy += j;
            }
    sx /= qx;
    sy /= qy;
    printf("%d %d\n",1+sx,1+sy);
}