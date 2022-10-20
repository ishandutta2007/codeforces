#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100];

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=1;i<=k;i++) scanf("%d", a+i);
    vector<int> V;
    for (int i=2;i<=k;i++) V.push_back(a[i] - a[i-1]);

    bool flag = 1;
    for (int i=1;i<(int)V.size();i++) if (V[i-1] > V[i]) flag = 0;
    if (!V.empty() && a[1] > (ll)V[0] * (n-k+1)) flag = 0;
    if (flag) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}