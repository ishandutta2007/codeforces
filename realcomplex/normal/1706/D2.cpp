#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 5;
int nex[N];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 0 ; i < N ; i ++ ) nex[i] = -1;
    int a;
    int sol = N;
    bool can = true;
    int big = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> a;
        if(a >= k) can = false;
        nex[a]=a;
        big = max(big, a);
    }
    for(int i = N - 2; i >= 0 ; i -- ){
        if(nex[i]==-1)nex[i]=nex[i+1];
    }
    if(can) sol = 0;
    int low;
    int high;
    int small;
    for(int v = 1; v < N; v ++ ){
        small = v;
        for(int i = 1; i <= k ; i ++ ){
            low = (i - 1) * 1ll * (v + 1);
            high = i * v + (i - 1);
            if(low >= N) break;
            if(nex[low] != -1 && nex[low] <= v * i + v - 1){
                small = min(small, nex[low] / i);
            }
        }
        if(big / k <= v)
            sol = min(sol, v - small);
    }
    cout << sol << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}