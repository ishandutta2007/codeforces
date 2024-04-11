#include <bits/stdc++.h>
#define int long long

typedef long long ll;
using namespace std;

void solve(){
    int n, l, r, s;
    scanf("%lld %lld %lld %lld", &n, &l, &r, &s);
    int s1=0, s2=0, m = r-l+1;
    for (int i=0;i<m;i++) s1 += i+1, s2 += n-i;
    if (s<s1 || s>s2){
        printf("-1\n"); return;
    }
    vector<int> ans;
    for (int i=0;i<m;i++) ans.push_back(n-i);
    reverse(ans.begin(), ans.end());
    for (int i=0;i<m;i++){
        if (s2>s){
            if (s2-s>ans[i]-i-1){
                s2 -= ans[i]-i-1;
                ans[i] = i+1;
            }
            else{
                ans[i] -= s2-s;
                s2 = s;
            }
        }
    }
    vector<bool> chk(n);
    vector<int> rans(n);
    for (int i=0;i<m;i++){
        chk[ans[i]-1]=1;
    }
    int pt1=0;
    if (pt1==l-1) pt1=r;
    for (int i=0;i<n;i++){
        if (chk[i]) continue;
        rans[pt1] = i+1;
        pt1++;
        if (pt1==l-1) pt1 = r;
    }
    for (int i=0;i<m;i++) rans[l+i-1] = ans[i];
    for (int i=0;i<n;i++) printf("%lld ", rans[i]);
    printf("\n");
}

signed main(){
    int t;
    scanf("%lld", &t);
    while(t--){
        solve();
    }
    return 0;
}