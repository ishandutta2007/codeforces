#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> p[2020], adj[2020];
int dep[2020], tmp[2020];
bool visited[2020];

int main(){
    int n;
    scanf("%d", &n);
    printf("? 1\n");
    fflush(stdout);
    int cnt = 0;
    for (int i=1;i<=n;i++){
        scanf("%d", dep+i);
        if (dep[i]&1) cnt++;
    }
    if (cnt<n/2){
        for (int i=1;i<=n;i++) if (dep[i]&1){
            printf("? %d\n", i);
            fflush(stdout);
            for (int j=1;j<=n;j++){
                scanf("%d", tmp+j);
                if (tmp[j]==1) adj[i].push_back(j);
            }
        }
    }
    else{
        for (int i=1;i<=n;i++){
            if (dep[i]==1) adj[1].push_back(i);
            else if (dep[i]>0 && dep[i]%2==0){
                printf("? %d\n", i);
                fflush(stdout);
                for (int j=1;j<=n;j++){
                    scanf("%d", tmp+j);
                    if(tmp[j]==1) adj[i].push_back(j);
                }
            }
        }
    }
    printf("!\n");
    fflush(stdout);
    for (int i=1;i<=n;i++){
        for (auto &x:adj[i]){
            printf("%d %d\n", i, x);
            fflush(stdout);
        }
    }
    return 0;
}