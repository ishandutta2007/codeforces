#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    if (a==1){
        if ((n-1)%b==0) printf("Yes\n");
        else printf("No\n");
    }
    else{
        vector<ll> vec;
        ll cur = 1;
        while(cur<1e9+10){
            vec.push_back(cur);
            cur *= a;
        }
        bool flag = 0;
        for (auto &x:vec) if (n>=x && (n-x)%b==0) flag = 1;
        if (flag) printf("Yes\n");
        else printf("No\n");
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