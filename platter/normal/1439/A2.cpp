#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[101][101];
typedef pair<int,int> P;
vector<P> ret;

void func() {
    printf("%d\n",ret.size()/3);
    for(int i=0;i<ret.size();i++) {
        printf("%d %d ",ret[i].first,ret[i].second);
        if (i%3==2) {
            printf("\n");
        }
    }
}

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d %d\n",&n,&m);
        ret.clear();
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                scanf("%1d",&arr[i][j]);
            }
            scanf("\n");
        }
        for(int i=2;i<=n;i++) {
            if (m==2) {
                break;
            }
            for(int j=2;j<=m;j++) {
                if (arr[i-1][j-1]==1||arr[i][j-1]==1) {
                    int cnt=0;
                    if (arr[i-1][j-1]==1) {
                        ret.push_back(P(i-1,j-1));
                        arr[i-1][j-1]=0;
                        cnt++;
                    }
                    if (arr[i][j-1]==1) {
                        ret.push_back(P(i,j-1));
                        arr[i][j-1]=0;
                        cnt++;
                    }
                    for(int k=0;k<3-cnt;k++) {
                        ret.push_back(P(i-1+k,j));
                        arr[i-1+k][j]^=1;
                    }
                }
            }
        }
        for(int i=2;i<=n;i++) {
            if (arr[i-1][m-1]==1||arr[i-1][m]==1) {
                int cnt=0;
                if (arr[i-1][m-1]==1) {
                    ret.push_back(P(i-1,m-1));
                    arr[i-1][m-1]=0;
                    cnt++;
                }
                if (arr[i-1][m]==1) {
                    ret.push_back(P(i-1,m));
                    arr[i-1][m]=0;
                    cnt++;
                }
                for(int j=0;j<3-cnt;j++) {
                    ret.push_back(P(i,m-1+j));
                    arr[i][m-1+j]^=1;
                }
            }
        }
        if (arr[n][m-1]==0&&arr[n][m]==0) {
            func();
        }
        else if (arr[n][m-1]==0&&arr[n][m]==1) {
            int x=n;
            int y=m;
            int cnt=0;
            while (cnt<9) {
                ret.push_back(P(x,y));
                cnt++;
                if (x==n) {
                    if (y==m) {
                        y--;
                    }
                    else {
                        x--;
                    }
                }
                else {
                    if (y==m) {
                        x++;
                    }
                    else {
                        y++;
                    }
                }
            }
            func();
        }
        else if (arr[n][m-1]==1&&arr[n][m]==0) {
            int x=n;
            int y=m-1;
            int cnt=0;
            while (cnt<9) {
                ret.push_back(P(x,y));
                cnt++;
                if (x==n) {
                    if (y==m) {
                        y--;
                    }
                    else {
                        x--;
                    }
                }
                else {
                    if (y==m) {
                        x++;
                    }
                    else {
                        y++;
                    }
                }
            }
            func();
        }
        else {
            int x=n-1;
            int y=m-1;
            int cnt=0;
            while (cnt<6) {
                ret.push_back(P(x,y));
                cnt++;
                if (x==n) {
                    if (y==m) {
                        y--;
                    }
                    else {
                        x--;
                    }
                }
                else {
                    if (y==m) {
                        x++;
                    }
                    else {
                        y++;
                    }
                }
            }
            func();
        }
    }
}