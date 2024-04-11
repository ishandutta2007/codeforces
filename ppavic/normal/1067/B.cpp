#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N = 1e5 + 500;

queue < int > q;
int n, deg[N], ty[N], bio[N], cnt = 0, k, rl[N];
vector < int > v[N];

int main(){
    memset(ty, -1, sizeof(ty));
    scanf("%d%d", &n, &k);
    for(int i = 1;i<n;i++){
        int x, y;scanf("%d%d", &x, &y);
        deg[x]++, deg[y]++;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1;i<=n;i++)
        if(deg[i] == 1)
            q.push(i), ty[i] = 0;
    while(!q.empty()){
        cnt++;
        int x = q.front();
        q.pop();
        bio[x] = 1;
        if(ty[x] && rl[x] < 3){
            printf("No\n");
            return 0;
        }
        if(cnt == n){
            if(ty[x] == k){
                printf("Yes\n");
                return 0;
            }
            break;
        }
        if(deg[x] != 1){
            printf("No\n");
            return 0;
        }
        for(int y : v[x]){
            if(bio[y]) continue;
            deg[y]--;
            rl[y]++;
            if(ty[y] != -1 && ty[y] != ty[x] + 1){
                printf("No\n");
                return 0;
            }
            ty[y] = ty[x] + 1;
            if(deg[y] == 1)
                q.push(y);
        }
    }
    printf("No\n");
    return 0;
}