#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100], b[100100];
vector<int> cnt[100100];

void solve(){
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    for (int i=1;i<=n+1;i++) cnt[i].clear();
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
        cnt[a[i]].push_back(i);
    }
    fill(b, b+n, -1);
    int z = -1;
    for (int i=1;i<=n+1;i++) if (cnt[i].empty()) z = i;
    assert(z!=-1);
    priority_queue<pair<int, int>> pq;
    for (int i=1;i<=n+1;i++) pq.push(make_pair(cnt[i].size(), i));
    for (int i=0;i<x;i++){
        auto p = pq.top(); pq.pop();
        b[cnt[p.second].back()] = p.second;
        cnt[p.second].pop_back();
        p.first--;
        pq.push(p);
    }

    vector<pair<int, int>> vec;
    vector<bool> chk;
    for (int i=0;i<n;i++) if (b[i]==-1) vec.emplace_back(a[i], i);
    sort(vec.begin(), vec.end());
    int m = vec.size();
    for (int i=0;i<m;i++){
        int j = i+m/2;
        if (j>=m) j -= m;
        b[vec[j].second] = vec[i].first;
    }
    chk.resize(m);
    int cnt = 0;
    for (int i=0;i<m;i++) if (a[vec[i].second]==b[vec[i].second]){
        b[vec[i].second] = z;
        chk[i] = 1;
        cnt++;
    }
    if (cnt>n-y){
        printf("NO\n"); return;
    }
    for (int i=0;i<m;i++) if (!chk[i]){
        if (cnt>=n-y) break;
        b[vec[i].second] = z;
        cnt++;
    }
    printf("YES\n");
    for (int i=0;i<n;i++) printf("%d ", b[i]);
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