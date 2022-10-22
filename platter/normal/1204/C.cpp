#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    scanf("%d\n",&n);
    int dist[100][100];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int x;
            scanf("%1d",&x);
            if (x==1) {
                dist[i][j]=1;
            }
            else {
                dist[i][j]=1e9;
            }
        }
        scanf("\n");
    }
    for(int i=0;i<n;i++) {
        dist[i][i]=0;
    }
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    int m;
    scanf("%d\n",&m);
    int l=1;
    int prev;
    scanf("%d ",&prev);
    prev--;
    int before=prev;
    int ret[1000000];
    ret[0]=prev;
    int cnt=0;
    int x;
    for(int i=1;i<m;i++) {
        cnt++;
        scanf("%d ",&x);
        x--;
        if (dist[prev][x]!=cnt) {
            ret[l]=before;
            l++;
            prev=before;
            cnt=1;
        }
        before=x;
    }
    ret[l++]=x;
    printf("%d\n",l);
    for(int i=0;i<l;i++) {
        printf("%d ",ret[i]+1);
    }
    return 0;
}