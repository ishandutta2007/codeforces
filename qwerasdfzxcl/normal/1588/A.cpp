#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i=0;i<n;i++) scanf("%d", &a[i]);
    for (int i=0;i<n;i++) scanf("%d", &b[i]);

    while(!a.empty()){
        auto iter1 = max_element(a.begin(), a.end()), iter2 = max_element(b.begin(), b.end());
        if (*iter1>*iter2) {printf("NO\n"); return;}
        else if (*iter1+1<*iter2) {printf("NO\n"); return;}
        a.erase(iter1); b.erase(iter2);
    }
    printf("YES\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}