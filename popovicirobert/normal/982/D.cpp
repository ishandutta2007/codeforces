#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

pair <int, int> arr[MAXN + 1];

struct Data {
    int sef;
    int len;
}v[MAXN + 1];

int aux[MAXN + 1];

int myfind(int x) {
    if(v[x].sef == 0)
        return x;
    return v[x].sef = myfind(v[x].sef);
}

int fr[MAXN + 1];

inline void myunion(int x, int y) {
    x = myfind(x);
    y = myfind(y);
    if(x != y) {
        v[x].sef = y;
        fr[v[x].len]--;
        fr[v[y].len]--;
        v[y].len += v[x].len;
        fr[v[y].len]++;
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
        aux[i] = arr[i].first;
    }
    sort(arr + 1, arr + n + 1);
    int cnt = 0, mx = 0, ans = 0;
    for(i = 1; i <= n; i++) {
        int pos = arr[i].second;
        v[pos].len = 1;
        cnt++;
        fr[1]++;
        if(pos > 1 && aux[pos - 1] < arr[i].first) {
            cnt--;
            myunion(pos - 1, pos);
        }
        if(pos < n && aux[pos + 1] < arr[i].first) {
            cnt--;
            myunion(pos + 1, pos);
        }
        if(fr[v[pos].len] == cnt) {
            if(cnt > mx) {
                mx = cnt;
                ans = arr[i].first + 1;
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}