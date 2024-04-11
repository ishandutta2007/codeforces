#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll a[200200], b[200200];
vector<ll> x1, x2, yx2;

void solve(){
    x1.clear();
    x2.clear();
    yx2.clear();
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++) scanf("%lld", a+i);
    ll tmp=0;
    for (int i=0;i<n;i++) tmp += a[i];
    for (int i=0;i<n;i++){
        scanf("%lld", b+i);
        if (b[i]==1) x1.push_back(a[i]);
        else x2.push_back(a[i]);
    }
    if (tmp<m){
        printf("-1\n");
        return;
    }
    sort(x1.begin(), x1.end());
    sort(x2.begin(), x2.end());
    ll ans1=1, ans2=0, tmp1=0, tmp2=0;
    if (x1.size()) tmp1 += x1.back();
    for (int i=(int)x1.size()-2;i>=1;i -= 2){
        yx2.push_back(x1[i]+x1[i-1]);
    }
    int pt1=x2.size()-1, pt2=0;
    while(tmp1<m && (pt1!=-1 || pt2!=(int)yx2.size())){
        if (pt1==-1){
            tmp1 += yx2[pt2++];
            ans1 += 2;
        }
        else if (pt2==(int)yx2.size()){
            tmp1 += x2[pt1--];
            ans1 += 2;
        }
        else{
            if (x2[pt1]>yx2[pt2]){
                tmp1 += x2[pt1--];
                ans1 += 2;
            }
            else{
                tmp1 += yx2[pt2++];
                ans1 += 2;
            }
        }
    }
    yx2.clear();
    for (int i=(int)x1.size()-1;i>=1;i -= 2){
        yx2.push_back(x1[i]+x1[i-1]);
    }
    pt1=x2.size()-1, pt2=0;
    while(tmp2<m && (pt1!=-1 || pt2!=(int)yx2.size())){
        if (pt1==-1){
            tmp2 += yx2[pt2++];
            ans2 += 2;
        }
        else if (pt2==(int)yx2.size()){
            tmp2 += x2[pt1--];
            ans2 += 2;
        }
        else{
            if (x2[pt1]>yx2[pt2]){
                tmp2 += x2[pt1--];
                ans2 += 2;
            }
            else{
                tmp2 += yx2[pt2++];
                ans2 += 2;
            }
        }
    }
    ll ans=1e18;
    if (tmp1>=m) ans=min(ans, ans1);
    if (tmp2>=m) ans=min(ans, ans2);
    if (ans==1e18) ans /= 0;
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}