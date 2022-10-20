#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200];
vector<int> tmp;

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    tmp.clear();
    for (int i=0;i<n;i++) tmp.push_back((a[i]+i+1000000000)%n);
    sort(tmp.begin(), tmp.end());
    bool ans=1;
    for (int i=1;i<n;i++) if (tmp[i]==tmp[i-1]) ans=0;
    if (ans) printf("YES\n");
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