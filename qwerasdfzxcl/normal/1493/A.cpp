#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> ans;
    for (int i=k+1;i<=n;i++) ans.push_back(i);
    for (int i=k-1;i>=(k+1)/2;i--) ans.push_back(i);
    printf("%d\n", (int)ans.size());
    for (int x:ans) printf("%d ", x);
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