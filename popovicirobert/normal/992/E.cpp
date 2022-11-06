#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 2e5;

int arr[MAXN + 1];

ll aib[MAXN + 1];

inline void update(int pos, int n, int val) {
    for(int i = pos; i <= n; i += lsb(i)) {
        aib[i] += val;
    }
}

inline ll query(int pos) {
    ll ans = 0;
    for(int i = pos; i > 0; i -= lsb(i)) {
        ans += aib[i];
    }
    return ans;
}

int aint[4 * MAXN + 1];

void update(int nod, int left, int right, int pos, int val) {
    if(left == right) {
        aint[nod] = val;
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

int get(int nod, int left, int right, int l, int r, ll val) {
    if(l <= left && right <= r) {
        if(aint[nod] < val)
            return -1;
        if(left == right)
            return left;
        else {
            int mid = (left + right) / 2;
            if(aint[2 * nod] >= val)
                return get(2 * nod, left, mid, l, r, val);
            else
                return get(2 * nod + 1, mid + 1, right, l, r, val);
        }
    }
    else {
        int mid = (left + right) / 2;
        int ans = -1;
        if(l <= mid && aint[2 * nod] >= val) {
            ans = get(2 * nod, left, mid, l, r, val);
        }
        if(ans == -1 && aint[2 * nod + 1] >= val) {
            ans = get(2 * nod + 1, mid + 1, right, l, r, val);
        }
        return ans;
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, q;
    //ios::sync_with_stdio(false);
    //cin >> n >> q;
    scanf("%d%d" ,&n,&q);
    for(i = 1; i <= n; i++) {
        //cin >> arr[i];
        scanf("%d" ,&arr[i]);
        update(i, n, arr[i]);
        update(1, 1, n, i, arr[i]);
    }
    while(q > 0) {
        q--;
        int p, x;
        //cin >> p >> x;
        scanf("%d%d" ,&p,&x);
        update(p, n, x - arr[p]);
        update(1, 1, n, p, x);
        arr[p] = x;
        int ans = -1;
        if(arr[1] == 0) {
            ans = 1;
        }
        else {
            int pos = 1;
            while(pos < n) {
                pos = get(1, 1, n, pos + 1, n, query(pos));
                if(pos == -1)
                    break;
                if(query(pos) == 2 * arr[pos]) {
                    ans = pos;
                    break;
                }
            }
        }
        printf("%d\n" ,ans);
        //cout << ans << "\n";
    }
    //cin.close();
   // cout.close();
    return 0;
}