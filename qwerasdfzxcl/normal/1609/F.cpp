#include <bits/stdc++.h>
#define int long long

typedef long long ll;
using namespace std;
const int INF = 2e18;
vector<pair<int, int>> V[64], V2[64];
ll a[1001000], ans, pt[64], pt2[64];

bool chk(int x, int y){
    return __builtin_popcountll(x) == __builtin_popcountll(y);
}

bool mid(int x, int y, int z){
    return x<=y && y<=z;
}

void solve(int l, int r, int m, bool flip){

    int s = m, e = m+1;
    ll mn = min(a[s], a[e]), mx = max(a[s], a[e]), mn2 = INF, mx2 = -INF;
    int mnx = s, mxx = s;
    if (a[s]<a[e]) mxx = e;
    if (a[s]>a[e]) mnx = e;

    while(s>=l){
        if (mnx<=m && mxx<=m && chk(mn, mx)){
            int cntl = 0;
            while(s>=l && mid(mn, a[s], mx)) {s--, cntl++;}
            while(e<=r && mid(mn, a[e], mx)){
                mn2 = min(mn2, a[e]);
                mx2 = max(mx2, a[e]);
                if (flip && mn2==mn && mx2==mx) break;
                e++;
            }
            ans += cntl * (e-m-1);
            s++;
        }
        if (s==l) break;
        --s;
        if (a[s]<=mn) mn = a[s], mnx = s;
        if (a[s]>=mx) mx = a[s], mxx = s;
    }

    for (int i=0;i<64;i++){
        V[i].clear();
        V2[i].clear();
        pt[i] = pt2[i] = 0;
    }

    mx = -INF;
    for (int i=m+1;i<=r;){
        mx = max(mx, a[i]);
        if (a[i]==mx){
            int prv = i, val = __builtin_popcountll(mx);
            V2[val].emplace_back(i, 0);

            while(i<=r && a[i]<=mx) i++;
            V[val].emplace_back(mx, i-prv);
            V2[val].back().second = i-prv;
            continue;
        }
        i++;
    }

    for (int i=0;i<64;i++){
        for (int j=(int)V[i].size()-2;j>=0;j--) V[i][j].second += V[i][j+1].second;
    }

    s = m, e = m+1;
    mn = INF, mx = -INF;
    while(s>=l){
        mn = min(mn, a[s]);
        mx = max(mx, a[s]);


        while(e<=r && a[e]>mn) e++;

        int idx = __builtin_popcountll(mn);

        while(pt[idx]<(int)V[idx].size()){
            if (V[idx][pt[idx]].first>mx) break;
            pt[idx]++;
        }


        if (pt2[idx] > pt[idx]){
            ans += V[idx][pt[idx]].second - V[idx][pt2[idx]].second;
        }

        while(pt2[idx]<(int)V[idx].size()){
            if (V2[idx][pt2[idx]].first>=e) break;
            if (V2[idx][pt2[idx]].first + V2[idx][pt2[idx]].second <=e) {
                if (pt2[idx]>=pt[idx]) ans += V2[idx][pt2[idx]].second;
                pt2[idx]++;  continue;
            }

            if (pt2[idx]>=pt[idx]) ans += (e - V2[idx][pt2[idx]].first);
            pt2[idx]++;
        }

        if (pt2[idx]) pt2[idx]--;
        --s;
    }
}

void dnc(int l, int r){
    if (l==r) {ans++; return;}
    int m = (l+r)>>1;
    solve(l, r, m, 0);
    reverse(a+l, a+r+1);
    solve(l, r, r+l-m-1, 1);
    reverse(a+l, a+r+1);

    dnc(l, m); dnc(m+1, r);
}

signed main(){
    int n;
    scanf("%lld", &n);
    for (int i=1;i<=n;i++) scanf("%lld", a+i);

    dnc(1, n);
    printf("%lld\n", ans);
    return 0;
}