#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5 + 5;

ll arr[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, l;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> l;
    int cnt = 0;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        if(arr[i] > l && arr[i - 1] <= l) {
            cnt++;
        }
    }
    while(m > 0) {
        m--;
        int type;
        cin >> type;
        if(type == 0) {
            cout << cnt << "\n";
        }
        else {
            int p, d;
            cin >> p >> d;
            ll aux = arr[p];
            arr[p] += d;
            if(aux <= l) {
                if(arr[p] > l) {
                    if(arr[p - 1] <= l && arr[p + 1] <= l) {
                        cnt++;
                    }
                    else if(arr[p - 1] > l && arr[p + 1] > l) {
                        cnt--;
                    }
                }
            }
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}