#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    for (int i=30;i>=0;i--){
        int cnt1 = 0, cnt0 = 0;
        for (int j=0;j<n;j++){
            if (a[j]&(1<<i)) cnt1++;
            else cnt0++;
        }
        if (cnt1%2==0) continue;
        if (cnt1%4==3 && cnt0%2==0){
            printf("LOSE\n");
            return;
        }
        else{
            printf("WIN\n");
            return;
        }
    }
    printf("DRAW\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}