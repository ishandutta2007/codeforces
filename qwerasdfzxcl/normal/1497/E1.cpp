#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200100];
set<int> chk;

int factor(int n){
    int ret=1;
    int n1=n;
    for (int i=2;i*i<=n1;i++){
        if (n%i) continue;
        int tmp=0;
        while(n%i==0){
            tmp++; n/=i;
        }
        if (tmp%2==0) continue;
        else ret *= i;
    }
    if (n>1) ret *= n;
    return ret;
}

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    int ans=0;
    chk.clear();
    for (int i=0;i<n;i++){
        int tmp = factor(a[i]);
        if (chk.find(tmp)!=chk.end()){
            ans++;
            chk.clear();
            chk.insert(tmp);
        }
        else{
            chk.insert(tmp);
        }
    }
    printf("%d\n", ans+1);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}