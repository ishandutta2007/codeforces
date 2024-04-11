#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
bool vis[100000];
int nt[100000];
 
int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) {
            nt[i]=-1;
            vis[i]=false;
        }
        int ret=0;
        for(int i=0;i<m;i++) {
            int x,y;
            scanf("%d %d",&x,&y);
            x--;
            y--;
            if (x==y) {
                continue;
            }
            nt[x]=y;
            ret++;
        }
        for(int i=0;i<n;i++) {
            int cnt=0;
            if (nt[i]==-1||vis[i]) {
                continue;
            }
            int now=i;
            while (now!=i||cnt==0) {
                vis[now]=true;
                now=nt[now];
                cnt++;
                if (now==-1) {
                    break;
                }
            }
            if (now==i)
                ret++;
        }
        printf("%d\n",ret);
    }
}