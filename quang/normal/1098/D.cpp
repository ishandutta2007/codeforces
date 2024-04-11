#include <bits/stdc++.h>

using namespace std;

const int N = 500010;
const int INF = 2e9;

int q;
pair<char, int> queries[N];
vector<int> val;

struct IT {
    long long sum[N << 2];
    int maxVal[N << 2];

    void init(int node, int l, int r) {
        sum[node] = 0;
        maxVal[node] = 0;
        if (l == r) return;
        int m = (l + r) >> 1;
        init(node << 1, l, m);
        init(node << 1 | 1, m + 1, r);
    }

    void add(int node, int l, int r, int id, int sign) {
        if (id > r || id < l) return;
        if (l == r) {
            sum[node] += val[id] * sign;
            if (sum[node] == 0) maxVal[node] = 0;
            else maxVal[node] = val[id];
            return;
        }
        int m = l + r >> 1;
        add(node << 1, l, m, id, sign);
        add(node << 1 | 1, m + 1, r, id, sign);
        sum[node] = sum[node << 1] + sum[node << 1 | 1];
        maxVal[node] = max(maxVal[node << 1], maxVal[node << 1 | 1]);
    }

    int find(int node, int l, int r, long long need) {
        if (maxVal[node] <= need) {
            return val.size();
        }
        if (l == r) return l;
        int m = l + r >> 1;
        if (maxVal[node << 1] > need) return find(node << 1, l, m, need);
        else return find(node << 1 | 1, m + 1, r, need);
    }   

    long long getVal(int node, int l, int r, int id) {
        if (l == r) return sum[node];
        int m = l + r >> 1;
        if (id <= m) return getVal(node << 1, l, m, id);
        else return sum[node << 1] + getVal(node << 1 | 1, m + 1, r, id);
    }
} it;

int getRes() {
    int res = 0;
    int curId = 0;
    long long now = 0;
    // cerr << "start \n";
    while (1) {
        int opt = it.find(1, 1, val.size() - 1, now * 2) - 1;
        // cerr << curId << " " << opt << " " << now << endl;
        if (opt == curId) {
            curId++;
            res++;
        } else {
            curId = opt;
        }
        if (curId >= val.size()) break;
        now = it.getVal(1, 1, val.size() - 1, curId);
    }
    return res - 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        char op;
        int x;
        cin >> op >> x;
        queries[i] = {op, x};
        if (op == '+') val.push_back(x);
    }
    val.push_back(0);
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    it.init(1, 1, val.size() - 1);
    int numFish = 0;
    for (int i = 1; i <= q; i++) {
        int id = lower_bound(val.begin(), val.end(), queries[i].second) - val.begin(); 
        if (queries[i].first == '+') {
            it.add(1, 1, val.size() - 1, id, 1);
            numFish++;
        } else { 
            it.add(1, 1, val.size() - 1, id, -1);
            numFish--;
        }

        int foo = getRes();
        cout << numFish - foo << '\n';
    }
    return 0;
}