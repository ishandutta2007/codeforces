#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int matrix[2005][2005];
int xmin[10];
int ymin[10];
int xmax[10];
int ymax[10];
int c[10]={0};
int ans[10];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        for (int i=0;i<10;i++){
            xmin[i]=987654321;
            ymin[i]=987654321;
            xmax[i]=-987654321;
            ymax[i]=-987654321;
            c[i]=0;
            ans[i]=-987654321;
        }
        int n;
        scanf("%d", &n);
        char tmp[2005];
        for (int i=0;i<n;i++) {
            scanf("%s", tmp);
            for (int j=0;j<n;j++){
                matrix[i][j]=tmp[j]-48;
                int tmp1=matrix[i][j];
                c[matrix[i][j]]++;
                xmin[tmp1]=min(xmin[tmp1], j);
                xmax[tmp1]=max(xmax[tmp1], j);
                ymin[tmp1]=min(ymin[tmp1], i);
                ymax[tmp1]=max(ymax[tmp1], i);
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                int tmp2=max(i, n-1-i), tmp3=max(j, n-1-j);
                int digit=matrix[i][j];
                if (c[digit]==1) ans[digit]=0;
                ans[digit]=max(ans[digit], tmp2*max(abs(xmin[digit]-j), abs(xmax[digit]-j)));
                ans[digit]=max(ans[digit], tmp3*max(abs(ymin[digit]-i), abs(ymax[digit]-i)));
            }
        }
        for (int i=0;i<10;i++){
            if (c[i]==0) ans[i]=0;
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}