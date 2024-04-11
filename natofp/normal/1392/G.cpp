#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = 1e6 + 5;
const int LOG = 20;
int n, m, k;

vector<int> zloz(vector<int> a, vector<int> b){
    vector<int> res(a.size());
    for(int i=0;i<a.size();i++){
        res[i] = b[a[i]];
    }
    return res;
}

pii sw[nax];

int w1[nax];
int w2[nax];

int leftMost[1 << LOG];
int rightMost[1 << LOG];

void solve(){
    cin >> n >> m >> k;
    int m1 = 0, m2 = 0;
    string s1, s2; cin >> s1 >> s2;
    for(int i=0;i<k;i++){
        int val1 = s1[i] - '0';
        int val2 = s2[i] - '0';
        m1 += val1 * (1 << i);
        m2 += val2 * (1 << i);
    }
    for(int i=1;i<=n;i++){
        int x, y; cin >> x >> y;
        x -= 1;
        y -= 1;
        sw[i] = mp(x, y);
    }
    w1[0] = m1;
    w2[0] = m2;
    vector<int> permWas(k);
    for(int i=0;i<k;i++) permWas[i] = i;
    for(int i=1;i<=n;i++){
        vector<int> perm(k);
        for(int j=0;j<k;j++) perm[j] = j;
        perm[sw[i].st] = sw[i].nd;
        perm[sw[i].nd] = sw[i].st;
        permWas = zloz(perm, permWas);
        int m1Res = 0;
        int m2Res = 0;
        for(int j=0;j<k;j++){
            int to = permWas[j];
            if(m1 & (1 << j)) m1Res += (1 << to);
            if(m2 & (1 << j)) m2Res += (1 << to);
        }
        w1[i] = m1Res;
        w2[i] = m2Res;
    }
    int ans = -1;
    for(int i=0;i<(1<<LOG);i++){
        leftMost[i] = n + 1;
        rightMost[i] = -1;
    }
    for(int i=0;i<=n;i++){
        int v = w1[i];
        leftMost[v] = min(leftMost[v], i);
        v = w2[i];
        rightMost[v] = max(rightMost[v], i);
    }

    for(int i=(1<<LOG)-1;i>=0;i--){
        for(int j=0;j<LOG;j++){
            if(i & (1 << j)){
                int to = (i ^ (1 << j));
                leftMost[to] = min(leftMost[to], leftMost[i]);
                rightMost[to] = max(rightMost[to], rightMost[i]);
            }
        }
    }
    int allOnes = 0;
    for(int i=0;i<k;i++){
        if(m1 & (1 << i)) allOnes += 1;
        if(m2 & (1 << i)) allOnes += 1;
    }
    pii opt = mp(-1, -1);
    for(int i=0;i<(1<<LOG);i++){
        if(leftMost[i] + m <= rightMost[i]){
            int ones = __builtin_popcount(i);
            int ok = k - (allOnes - ones * 2);
            if(ok > ans){
                ans = ok;
                opt = mp(leftMost[i], rightMost[i]);
            }
        }
    }
    cout << ans << "\n";
    cout << opt.st + 1 << " " << opt.nd << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}