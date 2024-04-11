#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200], cnt[200200];
pair<int, int> ran;

bool valid(int n, int k, int L){
    ran = {-1, -1};

    int S = 0;
    for (int i=1;i<=k;i++) S += cnt[i];

    if (S>=L){
        ran = {1, k};
        return 1;
    }

    for (int i=k+1;i<=n;i++){
        S -= cnt[i-k];
        S += cnt[i];
        if (S>=L){
            ran = {i-k+1, i};
            return 1;
        }
    }
    return 0;
}

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);

    fill(cnt+1, cnt+n+1, 0);
    for (int i=1;i<=n;i++){
        scanf("%d", a+i);
        cnt[a[i]]++;
    }

    int L = n;
    for (int i=0;i<=n;i++) if (i*2 >= n+k) {L = i; break;}
    //printf("L = %d\n", L);

    int l = 1, r = n, val = n;
    while(l<=r){
        int m = (l+r)>>1;
        if (valid(n, m, L)) r = m-1, val = m;
        else l = m+1;
    }
    valid(n, val, L);

    vector<pair<int, int>> ans;
    int cur = 0, nxt = 1, idx = 1;
    for (int i=1;i<=n;i++){
        if (a[i]>=ran.first && a[i]<=ran.second) cur++;
        else cur--;

        if (cur==nxt && nxt!=k){
            ans.emplace_back(idx, i);
            nxt++;
            idx = i+1;
        }
    }

    ans.emplace_back(idx, n);

    //printf("-------------\n");
    printf("%d %d\n", ran.first, ran.second);
    for (auto &p:ans) printf("%d %d\n", p.first, p.second);
    //printf("-------------\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}