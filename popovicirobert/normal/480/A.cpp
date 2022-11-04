#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = 5000;

pair <int, int> arr[MAXN + 1];

int main() {
    //ifstream cin("C.in");
    //ofstream cout("C.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr + 1, arr + n + 1);
    int last = -1;
    for(i = 1; i <= n; i++) {
        if(arr[i].second >= last) {
            last = arr[i].second;
        }
        else {
            last = arr[i].first;
        }
    }
    cout << last;
    //cin.close();
    //cout.close();
    return 0;
}