#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[300300];
pair<ll, ll> inv[31];

void dnc(int k, vector<int>&pos){
    if (pos.empty()) return;
    //printf("%d\n", k);
    int prv = 0, prv2 = 0;
    ll cnt = 0, cnt2 = 0;
    vector<int> v0, v1;
    for (int i=0;i<(int)pos.size();i++){
        if (!(a[pos[i]]&(1<<k))){
            v0.push_back(pos[i]);
            cnt += prv;
            prv2++;
        }
        else{
            v1.push_back(pos[i]);
            cnt2 += prv2;
            prv++;
        }
    }
    inv[k].first += cnt;
    inv[k].second += cnt2;
    //if (k==3) printf("%lld %lld\n", cnt, tot);
    if (k){
        dnc(k-1, v0); dnc(k-1, v1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    vector<int> v(n);
    for (int i=0;i<n;i++) v[i] = i;
    dnc(30, v);
    int ans = 0;
    ll val = 0;
    for (int i=0;i<=30;i++){
        val += min(inv[i].first, inv[i].second);
        if (inv[i].second<inv[i].first) ans |= (1<<i);
    }
    printf("%lld %d\n", val, ans);
    return 0;
}