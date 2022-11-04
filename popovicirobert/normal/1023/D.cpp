#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

int arr[MAXN + 1], first[MAXN + 1], last[MAXN + 1];

int aint[4 * MAXN + 1];

void build(int nod, int left, int right) {
    if(left == right) {
        if(arr[left] == 0)
            aint[nod] = (1 << 30);
        else
            aint[nod] = arr[left];
    }
    else {
        int mid = (left + right) / 2;
        build(2 * nod, left, mid);
        build(2 * nod + 1, mid + 1, right);
        aint[nod] = min(aint[2 * nod], aint[2 * nod + 1]);
    }
}

int query(int nod, int left, int right, int l, int r) {
    if(l <= left && right <= r) {
        return aint[nod];
    }
    else {
        int mid = (left + right) / 2;
        int ans = (1 << 30);
        if(l <= mid)
            ans = min(ans, query(2 * nod, left, mid, l, r));
        if(mid < r)
            ans = min(ans, query(2 * nod + 1, mid + 1, right, l, r));
        return ans;
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, q;
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        if(first[arr[i]] == 0) {
            first[arr[i]] = i;
        }
        last[arr[i]] = i;
    }
    build(1, 1, n);
    bool flag = 1;
    for(i = 1; i <= q; i++) {
        if(first[i] > 0) {
            flag &= (query(1, 1, n, first[i], last[i]) >= i);
        }
    }
    if(flag == 0) {
        cout << "NO";
        return 0;
    }
    flag = 0;
    for(i = 1; i <= n; i++) {
        flag |= (arr[i] == q);
    }
    if(flag == 0) {
        for(i = 1; i <= n; i++) {
            if(arr[i] == 0) {
                arr[i] = q;
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << "\n";
    stack <int> stk;
    for(i = 1; i <= n; i++) {
        if(arr[i] > 0) {
            if(first[arr[i]] == i) {
                stk.push(arr[i]);
            }
            if(last[arr[i]] == i) {
                stk.pop();
            }
        }
        if(arr[i] > 0) {
            cout << arr[i] << " ";
        }
        else {
            if(stk.empty())
                cout << 1 << " ";
            else
                cout << stk.top() << " ";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}