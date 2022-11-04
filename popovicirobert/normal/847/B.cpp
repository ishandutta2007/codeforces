#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

int arr[MAXN + 1];
int aint[4 * MAXN + 1];

void update(int nod, int left, int right, int pos, int val) {
    if(left == right) {
        aint[nod] = val;
        arr[left] = val;
    }
    else {
        int mid = (left + right) / 2;
        if(pos <= mid)
            update(2 * nod, left, mid, pos, val);
        else
            update(2 * nod + 1, mid + 1, right, pos, val);
        aint[nod] = max(aint[2 * nod], aint[2 * nod + 1]);
    }
}

int query(int nod, int left, int right, int l, int r, int val) {
    if(l > r)
        return -1;
    if(left == right) {
        return left;
    }
    else {
        int mid = (left + right) / 2;
        int pos = -1;
        if(aint[2 * nod] > val && l <= mid) {
            pos = query(2 * nod, left, mid, l, r, val);
        }
        if(aint[2 * nod + 1] > val && mid < r && pos == -1) {
            pos = query(2 * nod + 1, mid + 1, right, l, r, val);
        }
        return pos;
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> x;
        update(1, 1, n, i, x);
    }
    int cnt = 0;
    while(cnt < n) {
        int last = 0, pos = 0;
        while(1) {
            pos = query(1, 1, n, pos + 1, n, last);
            if(pos == -1) {
                break;
            }
            cnt++;
            cout << arr[pos] << " ";
            last = arr[pos];
            update(1, 1, n, pos, -1);
        }
        cout << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}