#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44



using namespace std;

const int INF = 1e9;

struct SegTree {
    struct Node {
        int sum;
        int x, y, z;
        int xy, yz;
        int xyz;
    };

    vector <Node> aint;
    int n;

    inline void init(int _n) {
        n = _n;
        aint.resize(4 * n + 1, {-INF, -INF, -INF, -INF, -INF, -INF});
    }

    inline void refresh(int nod) {
        aint[nod].sum = aint[2 * nod].sum + aint[2 * nod + 1].sum;

        int sum = aint[2 * nod].sum;
        aint[nod].x = max(aint[2 * nod].x, aint[2 * nod + 1].x + sum);
        aint[nod].y = max(aint[2 * nod].y, aint[2 * nod + 1].y - 2 * sum);
        aint[nod].z = max(aint[2 * nod].z, aint[2 * nod + 1].z + sum);

        aint[nod].xy = max(max(aint[2 * nod].xy, aint[2 * nod + 1].xy - sum), aint[2 * nod].x + aint[2 * nod + 1].y - 2 * sum);
        aint[nod].yz = max(max(aint[2 * nod].yz, aint[2 * nod + 1].yz - sum), aint[2 * nod].y + aint[2 * nod + 1].z + sum);

        aint[nod].xyz = max(max(aint[2 * nod].xyz, aint[2 * nod + 1].xyz),
                            max(aint[2 * nod].xy + aint[2 * nod + 1].z + sum, aint[2 * nod].x + aint[2 * nod + 1].yz - sum));
    }

    void update(int nod, int left, int right, int pos, int val) {
        if(left == right) {
            aint[nod] = {val, val, -2 * val, val, -val, -val, 0};
        }
        else {
            int mid = (left + right) / 2;

            if(pos <= mid) update(2 * nod, left, mid, pos, val);
            else update(2 * nod + 1, mid + 1, right, pos, val);

            refresh(nod);
        }
    }

    void print(int nod, int left, int right) {
        if(left < right) {
            int mid = (left + right) / 2;
            print(2 * nod, left, mid);
            print(2 * nod + 1, mid + 1, right);
        }
        cerr << left << " " << right << "\n";
        cerr << aint[nod].xy << " " << aint[nod].yz << " " << aint[nod].xyz << "\n";
    }
};


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;
    cin >> n >> q >> str;
    n = 2 * (n - 1);
    str = " " + str;
    str[0] = '(';

    SegTree st; st.init(n);
    for(i = 0; i <= n; i++) {
        st.update(1, 0, n, i, str[i] == '(' ? 1 : -1);
    }

    //st.print(1, 1, n);

    cout << st.aint[1].xyz << "\n";

    while(q--) {
        int a, b;
        cin >> a >> b;
        swap(str[a], str[b]);

        for(auto i : {a, b}) {
            st.update(1, 0, n, i, str[i] == '(' ? 1 : -1);
        }

        cout << st.aint[1].xyz << "\n";
    }

    //cin.close();
    //cout.close();
    return 0;
}