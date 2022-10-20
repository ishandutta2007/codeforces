#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct query{
    int i, j, x;
    query(){}
    query(int _i, int _j, int _x): i(_i), j(_j), x(_x) {}
};
struct node{
    int ad, ai, i;
    node(){}
    node(int _ad, int _ai, int _i): ad(_ad), ai(_ai), i(_i) {}
    bool operator<(const node &N) const{
        return ai<N.ai;
    }
};
ll a[100100];
vector<query> ans;

bool comp(node &x, node &y){
    return x.ad<y.ad;
}

void solve(){
    int n;
    scanf("%d", &n);
    ll S=0;
    for (int i=1;i<=n;i++){
        scanf("%lld", a+i);
        S += a[i];
    }
    if (S%n){
        printf("-1\n");
        return;
    }
    S /= n;
    for (int i=2;i<=n;i++){
        ans.emplace_back(1, i, (i-a[i])%i);
        if (ans.back().x<0) ans.back().x += i;
        ans.emplace_back(i, 1, (a[i]+ans.back().x)/i);
    }
    for (int i=2;i<=n;i++) ans.emplace_back(1, i, S);
    assert((int)ans.size()<=n*3);
    printf("%d\n", (int)ans.size());
    for (auto &q:ans) printf("%d %d %d\n", q.i, q.j, q.x);
    ans.clear();
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}