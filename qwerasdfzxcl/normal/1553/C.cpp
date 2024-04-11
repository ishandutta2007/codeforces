#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char a[101];

bool _end(int x, int y, int r){
    int tmp = 10-r;
    int x1 = tmp/2;
    int y1 = tmp-x1;
    if (x+x1<y || x>y+y1) return 1;
    return 0;
}

void solve(){
    scanf("%s", a);
    int cnt1 = 0, cnt2 = 0;
    int ans = 10;
    for (int i=0;i<10;i++){
        if (_end(cnt1, cnt2, i)) {ans = i; break;}
        if (i&1){
            if (a[i]=='1') cnt2++;
        }
        else{
            if (a[i]=='1') cnt1++;
            else if (a[i]=='?') cnt1++;
        }
    }

    int ans2 = 10;
    cnt1 = 0, cnt2 = 0;
    for (int i=0;i<10;i++){
        if (_end(cnt1, cnt2, i)) {ans2 = i; break;}
        if (i&1){
            if (a[i]=='1') cnt2++;
            else if (a[i]=='?') cnt2++;
        }
        else{
            if (a[i]=='1') cnt1++;
        }
    }
    printf("%d\n", min(ans, ans2));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}