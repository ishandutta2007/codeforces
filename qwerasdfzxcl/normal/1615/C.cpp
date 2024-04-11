#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char a[100100], b[100100];

void solve(){
    int n;
    scanf("%d", &n);
    scanf("%s", a);
    scanf("%s", b);

    int ans1 = 1e9, ans2 = 1e9, val = 0;
    for (int i=0;i<n;i++){
        if (a[i]=='1') val++;
        if (b[i]=='1') val--;
    }

    if (val==0){
        ans1 = 0;
        for (int i=0;i<n;i++){
            if (a[i]!='1' && b[i]=='1') ans1 += 2;
        }
    }

    for (int i=0;i<n;i++){
        if (a[i]=='1') a[i] = '0';
        else a[i] = '1';
    }

    val = 0;
    for (int i=0;i<n;i++){
        if (a[i]=='1') val++;
        if (b[i]=='1') val--;
    }

    if (val==-1){
        ans2 = 1;
        for (int i=0;i<n;i++){
            if (a[i]=='1' && b[i]!='1') ans2 += 2;
        }
    }

    printf("%d\n", min(ans1, ans2)!=1e9?min(ans1, ans2):-1);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}