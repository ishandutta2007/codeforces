#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[1005][1005];
bool check[1005][1005];
int deg[1005][1005];
int p[1020000];

int Find(int a) {
    if (p[a]<0) {
        return a;
    }
    return p[a]=Find(p[a]);
}

void Merge(int a,int b) {
    a=Find(a);
    b=Find(b);
    if (a==b) {
        return;
    }
    p[b]=a;
}

typedef pair<int,int> P;

P find(int x,int y) {
    return P(Find(x*m+y)/m,Find(x*m+y)%m);
}

void merge(int x1,int y1,int x2,int y2) {
    Merge(x1*m+y1,x2*m+y2);
}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

bool valid(int x,int y) {
    return x>=0&&x<n&&y>=0&&y<m;
}

int main(void) {
    scanf("%d %d\n",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char x;
            scanf("%c",&x);
            if (x=='#') {
                arr[i][j]=1;
            }
            else {
                arr[i][j]=0;
            }
            check[i][j]=true;
        }
        scanf("\n");
    }
    for(int i=0;i<n;i++) {
        int flag=0;
        for(int j=0;j<m;j++) {
            if (arr[i][j]==1&&flag==0) {
                flag=1;
            }
            if (arr[i][j]==0&&flag==1) {
                flag=2;
            }
            if (flag==2) {
                check[i][j]=false;
            }
        }
        flag=0;
        for(int j=m-1;j>=0;j--) {
            if (arr[i][j]==1&&flag==0) {
                flag=1;
            }
            if (arr[i][j]==0&&flag==1) {
                flag=2;
            }
            if (flag==2) {
                check[i][j]=false;
            }
        }
    }
    for(int j=0;j<m;j++) {
        int flag=0;
        for(int i=0;i<n;i++) {
            if (arr[i][j]==1&&flag==0) {
                flag=1;
            }
            if (arr[i][j]==0&&flag==1) {
                flag=2;
            }
            if (flag==2) {
                check[i][j]=false;
            }
        }
        flag=0;
        for(int i=n-1;i>=0;i--) {
            if (arr[i][j]==1&&flag==0) {
                flag=1;
            }
            if (arr[i][j]==0&&flag==1) {
                flag=2;
            }
            if (flag==2) {
                check[i][j]=false;
            }
        }
    }
    for(int i=0;i<n;i++) {
        bool flag=false;
        for(int j=0;j<m;j++) {
            if (check[i][j]) {
                flag=true;
            }
        }
        if (!flag) {
            printf("-1");
            return 0;
        }
    }
    memset(p,-1,sizeof(p));
    for(int j=0;j<m;j++) {
        bool flag=false;
        for(int i=0;i<n;i++) {
            if (check[i][j]) {
                flag=true;
            }
        }
        if (!flag) {
            printf("-1");
            return 0;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if (arr[i][j]==1) {
                for(int k=0;k<4;k++) {
                    if (valid(i+dx[k],j+dy[k])) {
                        if (arr[i+dx[k]][j+dy[k]]==1) {
                            merge(i,j,i+dx[k],j+dy[k]);
                        }
                    }
                }
            }
        }
    }
    memset(check,0,sizeof(check));
    int ret=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if (arr[i][j]==1) {
                P pos=find(i,j);
                if (!check[pos.first][pos.second]) {
                    ret++;
                }
                check[pos.first][pos.second]=true;
            }
        }
    }
    printf("%d",ret);
}