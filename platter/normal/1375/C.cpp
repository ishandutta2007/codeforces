#include <bits/stdc++.h>
using namespace std;

int julde(int x) {
    return x>0?x:-x;
}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;

bool valid(int x,int y) {
    return x>=0&&x<n&&y>=0&&y<m;
}
int arr[300000];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
        printf("%s\n",arr[0]<arr[n-1]?"YES":"NO");
    }
}