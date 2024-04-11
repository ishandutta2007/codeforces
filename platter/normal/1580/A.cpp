#include <bits/stdc++.h>
using namespace std;

int n,m;
char arr[402][402];
int psum0[401][401];
int psum1[401][401];
int temp[401];

int f0(int x1,int y1,int x2,int y2) {
    return psum0[x2][y2]-psum0[x1-1][y2]-psum0[x2][y1-1]+psum0[x1-1][y1-1];
}

int f1(int x1,int y1,int x2,int y2) {
    return psum1[x2][y2]-psum1[x1-1][y2]-psum1[x2][y1-1]+psum1[x1-1][y1-1];
}

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d %d\n",&n,&m);
        for(int i=1;i<=n;i++) {
            scanf("%s",arr[i]+1);
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                psum0[i][j]=psum0[i-1][j]+psum0[i][j-1]-psum0[i-1][j-1]+(arr[i][j]=='0');
                psum1[i][j]=psum1[i-1][j]+psum1[i][j-1]-psum1[i-1][j-1]+(arr[i][j]=='1');
            }
        }
        int ret=1e8;
        for(int x1=1;x1<=n;x1++) {
            for(int x2=x1+4;x2<=n;x2++) {
                int pl=0;
                int val=1e8;
                for(int j=1;j<=m;j++) {
                    if (j>3) {
                        val=min(val,temp[j-3]);
                    }
                    //printf("%d %d\n",pl,val);
                    ret=min(ret,pl+val+f0(x1+1,j,x2-1,j));
                    pl+=(arr[x1][j]=='0')+(arr[x2][j]=='0')+f1(x1+1,j,x2-1,j);
                    temp[j]=-pl+f0(x1+1,j,x2-1,j);
                }
            }
        }
        printf("%d\n",ret);
    }
}