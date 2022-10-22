#include <bits/stdc++.h>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int p[1000005];

int n,m;

bool valid(int x,int y) {
    return x>=0&&x<n&&y>=0&&y<m;
}

int find(int a) {
    if (p[a]<0) {
        return a;
    }
    p[a]=find(p[a]);
    return p[a];
}

void merge(int a,int b) {
    a=find(a);
    b=find(b);
    if (a==b) {
        return;
    }
    p[a]+=p[b];
    p[b]=a;
}

int arr[1000005];

queue<int> q0;
queue<int> q1;
int dist0[1000005];
int dist1[1000005];
bool visited0[1000005];
bool visited1[1000005];
const int INF=1e8;

int main(void) {
    memset(p,-1,sizeof(p));
    int t;
    scanf("%d %d %d\n",&n,&m,&t);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%1d",&arr[i*m+j]);
        }
        scanf("\n");
    }
    for(int i=0;i<n*m;i++) {
        dist0[i]=INF;
        dist1[i]=INF;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            for(int k=0;k<4;k++) {
                if (valid(i+dx[k],j+dy[k])) {
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if (arr[i*m+j]==arr[x*m+y]) {
                        merge(i*m+j,x*m+y);
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if (p[find(i*m+j)]!=-1) {
                if (arr[i*m+j]==0) {
                    q0.push(i*m+j);
                    dist0[i*m+j]=0;
                    visited0[i*m+j]=true;
                }
                else{
                    q1.push(i*m+j);
                    dist1[i*m+j]=0;
                    visited1[i*m+j]=true;
                }
            }
        }
    }
    while (!q0.empty()) {
        int now=q0.front();
        q0.pop();
        int x=now/m;
        int y=now%m;
        for(int i=0;i<4;i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if (valid(nx,ny)) {
                if (!visited0[nx*m+ny]) {
                    if (p[find(nx*m+ny)]==-1) {
                        dist0[nx*m+ny]=dist0[x*m+y]+1;
                        visited0[nx*m+ny]=true;
                        q0.push(nx*m+ny);
                    }
                }
            }
        }
    }
    while (!q1.empty()) {
        int now=q1.front();
        q1.pop();
        int x=now/m;
        int y=now%m;
        for(int i=0;i<4;i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if (valid(nx,ny)) {
                if (!visited1[nx*m+ny]) {
                    if (p[find(nx*m+ny)]==-1) {
                        dist1[nx*m+ny]=dist1[x*m+y]+1;
                        visited1[nx*m+ny]=true;
                        q1.push(nx*m+ny);
                    }
                }
            }
        }
    }
    for(int i=0;i<t;i++) {
        int x,y;
        long long pe;
        scanf("%d %d %lld\n",&x,&y,&pe);
        x--;
        y--;
        if (p[find(x*m+y)]!=-1) {
            printf("%d\n",(arr[x*m+y]+pe)%2);
            continue;
        }
        if (dist0[x*m+y]==INF&&dist1[x*m+y]==INF) {
            printf("%d\n",arr[x*m+y]);
            continue;
        }
        int type=0;
        if (dist0[x*m+y]<dist1[x*m+y]) {
            type=0;
        }
        else {
            type=1;
        }
        if (type==0) {
            if (pe<dist0[x*m+y]) {
                printf("%d\n",arr[x*m+y]);
            }
            else {
                printf("%d\n",(pe-dist0[x*m+y]+arr[x*m+y])%2);
            }
        }
        else {
            if (pe<dist1[x*m+y]) {
                printf("%d\n",arr[x*m+y]);
            }
            else {
                printf("%d\n",(pe-dist1[x*m+y]+arr[x*m+y])%2);
            }
        }
    }
}