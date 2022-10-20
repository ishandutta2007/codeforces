#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
pair<int, int> a[100100];
int b[303][303];

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<m*n;i++){
        scanf("%d", &a[i].first);
        a[i].second = -i;
    }
    sort(a, a+m*n);
    int r = 0;
    for (int i=0;i<m*n;i=r){
        vector<int> pos;
        while(r<m*n && a[i].first==a[r].first){
            pos.push_back(-a[r].second);
            r++;
        }
        sort(pos.begin(), pos.end());
        int row = i/m, col = i%m, cur = r-i, cur2 = 0;
        while (cur>m-col){
            for (int j=col;j<m;j++) b[row][j] = pos[cur2+m-col-1-(j-col)];
            cur2 += m-col;
            cur -= m-col;
            row++;
            col = 0;
        }
        for (int j=col;j<col+cur;j++) b[row][j] = pos[cur2+(cur-1)-(j-col)];
    }
    ll ans = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            for (int k=0;k<j;k++) if (b[i][j]>b[i][k]) ans++;
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}