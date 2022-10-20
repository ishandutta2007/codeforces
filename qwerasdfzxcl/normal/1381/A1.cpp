#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char a[100100], b[100100];

void solve(){
    int n;
    scanf("%d", &n);
    scanf("%s %s", a, b);
    vector<int> ans;
    int l = 0, r = n-1, flip = 0;
    for (int i=n-1;i>=0;i--){
        int tmp2 = a[r] - '0', tmp3 = a[l]-'0';
        tmp2 ^= flip, tmp3 ^= flip;
        if (tmp2+'0'==b[i]) {
            if (l<r) r--;
            else r++;
            continue;
        }
        if (tmp3+'0'!=b[i]){
            ans.push_back(i+1);
            int tmp = l;
            if (l<r) tmp++;
            else tmp--;
            l = r;
            r = tmp;
            flip^=1;
        }
        else{
            ans.push_back(1);
            ans.push_back(i+1);
            int tmp = l;
            if (l<r) tmp++;
            else tmp--;
            l = r;
            r = tmp;
            flip^=1;
        }
    }
    printf("%d ", (int)ans.size());
    for (auto &x:ans) printf("%d ", x);
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