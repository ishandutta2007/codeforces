#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct R{
    int x, y, val;
    bool operator<(const R &r) const{
        return val<r.val;
    }
}a[10100];
int ans[101][101], pt[101], b[101][101];
bool visited[101][101];

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d", &a[i*m+j].val);
            a[i*m+j].x = i;
            a[i*m+j].y = j;
            b[i][j] = a[i*m+j].val;
        }
    }
    sort(a, a+n*m);
    for (int i=0;i<n;i++){
        pt[i] = 0;
        for (int j=0;j<m;j++) ans[i][j] = -1, visited[i][j] = 0;
    }
    for (int k=0;k<m;k++){
        ans[a[k].x][k] = a[k].val;
        visited[a[k].x][a[k].y] = 1;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (visited[i][j]) continue;
            while(ans[i][pt[i]]!=-1) pt[i]++;
            ans[i][pt[i]] = b[i][j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) printf("%d ", ans[i][j]);
        printf("\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}