#include <iostream>
#include <vector>

using namespace std;
int adj[100002];
bool visited[100002];
int cnt = 0, ans = 0, start;

void cycle(int x){
    visited[x] = true;
    cnt++;
    if(adj[x] == start){
        ans += cnt + 1;
        return;
    }
    if(adj[x] == 0){
        ans += cnt - 1;
        return;
    }
    if(visited[adj[x]]){
        ans += cnt;
        return;
    }
    cycle(adj[x]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        ans = 0;
        scanf("%d %d", &n, &m);
        for(int i=1;i<=n;i++){
            adj[i] = 0;
            visited[i] = false;
        }
        for(int i=1;i<=m;i++){
            int x, y;
            scanf("%d %d", &x, &y);
            if(x != y) adj[x] = y;
        }

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                start = i;
                cnt = 0;
                cycle(i);
            }
        }

        printf("%d\n", ans);
    }
}