#include <bits/stdc++.h>
using namespace std;

int arr[50][50];
int n;

bool valid(int x,int y) {
    return x>=0&&x<n&&y>=0&&y<n;
}

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d\n",&n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                scanf("%1d",&arr[i][j]);
            }
        }
        bool flag=true;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if (arr[i][j]==1) {
                    if (i==n-1||j==n-1) {
                        continue;
                    }
                    if (arr[i][j+1]==0&&arr[i+1][j]==0) {
                        flag=false;
                    }
                }
            }
        }
        printf("%s\n",flag?"YES":"NO");
    }
}