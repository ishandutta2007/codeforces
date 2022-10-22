#include <cstdio>
using namespace std;

int con[200001];
int visited[200001];
int fvisited[200001];
int ans[200001];
int n;
int length=0;

void fakedfs(int here) {
    length+=1;
    fvisited[here]=1;
    if (fvisited[con[here]]==0)
    fakedfs(con[here]);
}

void dfs(int here) {
    ans[here]=length;
    visited[here]=1;
    if (visited[con[here]]==0)
    dfs(con[here]);
}

void dfsall() {
    for(int i=1;i<=n;i++) {
        length=0;
        if (visited[i]==0) {
            fakedfs(i);
            dfs(i);
        }
    }
}

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        scanf("%d\n", &n);
        for(int i=1;i<=n;i++) {
            visited[i]=0;
            fvisited[i]=0;
            ans[i]=-1;
        }
        for(int i=1;i<=n;i++) {
            scanf("%d ", &con[i]);
        }
        scanf("\n");
        dfsall();
        for(int i=1;i<=n;i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}