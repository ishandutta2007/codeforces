#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 5e5 + 5;

int arr[MAXN + 1], n;
int aux[MAXN + 1], fr[MAXN + 1];

inline int check(int val) {
    int sz = 1;
    while(sz <= n && arr[sz] >= val) {
        aux[sz] = arr[sz];
        sz++;
    }
    int pos = sz;
    aux[sz] = val;
    sz++;
    while(sz <= n + 1) {
        aux[sz] = arr[sz - 1];
        sz++;
    }
    memset(fr, 0, sizeof(fr));
    ll s1 = 0, s2 = 0;
    int cnt = 0;
    for(int i = 2; i <= n + 1; i++) {
        if(aux[i] > 0) {
            fr[aux[i]]++;
            cnt++;
        }
    }
    /*for(int i = 1; i <= n + 1; i++) {
        cerr << aux[i] << " ";
    }
    cerr << "\n";*/
    for(int k = 1; k <= n + 1; k++) {
        s1 += aux[k];
        //cerr << s1 << " " << s2 + 1LL * cnt * k + 1LL * k * (k - 1) << "\n";
        if(s1 > s2 + 1LL * cnt * k + 1LL * k * (k - 1)) {
            if(k < pos) {
                //cerr << 0 << "\n";
                return 0;
            }
            //cerr << 2 << "\n";
            return 2;
        }
        cnt -= fr[k];
        s2 += 1LL * fr[k] * k;
        if(k <= n) {
            if(aux[k + 1] <= k) {
                s2 -= aux[k + 1];
            }
            else {
                fr[aux[k + 1]]--;
                cnt--;
            }
        }
    }
    //cerr << 1 << "\n";
    return 1;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int s = 0;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        s ^= (arr[i] & 1);
    }
    sort(arr + 1, arr + n + 1, greater<int>());
    int a = s - 2, b = s;
    for(int step = 1 << 18; step > 1; step >>= 1) {
        if(a + step <= n + 1 && check(a + step) == 0) {
            a += step;
        }
        if(b + step <= n + 1 && check(b + step) <= 1) {
            b += step;
        }
    }
    if(b - a < 2) {
        cout << -1;
        return 0;
    }
    for(i = a + 2; i <= b; i += 2) {
        cout << i << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}