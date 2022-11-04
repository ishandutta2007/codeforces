#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 2e5 + 5;
const ll INF = 1e18;

int arr[MAXN + 1];
int nxt[MAXN + 1];


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(i = n; i >= 1; i--) {
        if(arr[i + 1] != 1)
            nxt[i] = i + 1;
        else
            nxt[i] = nxt[i + 1];
    }
    ll ans = 0;
    for(i = 1; i <= n; i++) {
        ll prd = 1, sum = 0;
        int pos = i;
        while(pos <= n && prd <= INF / arr[pos]) {
            prd *= arr[pos];
            sum += arr[pos];
            if(prd == sum * k)
                ans++;
            int nr1 = nxt[pos] - pos - 1;
            if(prd % k == 0) {
                ll need = prd / k - sum;
                if(need > 0 && need <= nr1) {
                    ans++;
                }
            }
            sum += nr1;
            pos = nxt[pos];
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}