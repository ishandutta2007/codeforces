#include <bits/stdc++.h>
#define fi first
#define se second
#define db(x) cout << #x << " is " << x << "\n"
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
int arr[105], color[105];
int main() {
    IOS;
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    while (1) {
        int minim = 1e5;
        int ai = -1;
        for (int i = 1; i <= N; i++) {
            if (color[i] != 0) continue;
            if (minim > arr[i]) {
                minim = arr[i];
                ai = i;
            }
        }
        for (int i = 1; i <= N; i++) {
            if (color[i] != 0) continue;
            if (arr[i] % minim == 0) {
                color[i] = 1;
            }
        }
        if (ai == -1) break;
        ans++;
    }
    cout << ans << "\n";
}