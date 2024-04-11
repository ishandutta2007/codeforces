#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100];
int ans[100100];

void solve(){
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    set<pair<ll, int>> st;
    for (int i=0;i<m;i++) st.insert(make_pair(0, i+1));
    for (int i=0;i<n;i++){
        auto iter = st.begin();
        ans[i] = iter->second;
        auto p = *iter;
        p.first += a[i];
        st.erase(iter);
        st.insert(p);
    }
    printf("YES\n");
    for (int i=0;i<n;i++) printf("%d ", ans[i]);
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