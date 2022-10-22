#include <bits/stdc++.h>
using namespace std;

int dx[8]={0,1,-1,0,1,-1,0};
int dy[8]={1,1,0,0,0,-1,-1};

int main(void) {
    int n;
    scanf("%d",&n);
    printf("%d\n",3*n+4);
    for(int i=0;i<=n+1;i++) {
        printf("%d %d\n",i,i);
    }
    for(int i=0;i<=n;i++) {
        printf("%d %d\n%d %d\n",i,i+1,i+1,i);
    }
}