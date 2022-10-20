#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int c[100100], ans[100100];
vector<int> val[100100], inv[100100];

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<=n;i++){
        c[i]=0; inv[i].clear();
    }
    for (int i=0;i<=m;i++) val[i].clear();
    for (int i=0;i<m;i++){
        ans[i]=0;
        int k;
        scanf("%d", &k);
        for (int j=0;j<k;j++){
            int tmp;
            scanf("%d", &tmp);
            val[i].push_back(tmp);
            inv[tmp].push_back(i);
            c[tmp]++;
        }
    }
    int idx=-1;
    for (int i=1;i<=n;i++) if (c[i]>(m+1)/2){
        idx=i; break;
    }
    bool chk=0;
    int cnt=0;
    if (idx==-1){
        printf("YES\n");
        for (int i=0;i<m;i++) printf("%d ", val[i][0]);
        printf("\n");
        return;
    }
    for (int i=0;i<m;i++){
        if (val[i].size()==1 && val[i][0]==idx){
            if (cnt>=(m+1)/2){
                chk=1;
                break;
            }
            cnt++;
            ans[i]=idx;
        }
    }
    if (chk){
        printf("NO\n");
        return;
    }
    for (int x:inv[idx]){
        if (ans[x]) continue;
        if (cnt>=(m+1)/2) break;
        ans[x]=idx; cnt++;
    }
    printf("YES\n");
    for (int i=0;i<m;i++){
        if (ans[i]) printf("%d ", ans[i]);
        else if (val[i][0]==idx) printf("%d ", val[i][1]);
        else printf("%d ", val[i][0]);
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}