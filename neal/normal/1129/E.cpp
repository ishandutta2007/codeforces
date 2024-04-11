#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int query(const vector<int> &S, int v, const vector<int> &T) {
    if (S.empty() || T.empty())
        return 0;

    // cerr << endl;
    cout << S.size() << '\n';

    for (int i = 0; i < (int) S.size(); i++)
        cout << S[i] + 1 << (i < (int) S.size() - 1 ? ' ' : '\n');

    cout << T.size() << '\n';

    for (int i = 0; i < (int) T.size(); i++)
        cout << T[i] + 1 << (i < (int) T.size() - 1 ? ' ' : '\n');

    cout << v + 1 << '\n';
    cout << flush;
    int answer;
    cin >> answer;
    return answer;
}

int query(int s, int v, const vector<int> &T) {
    return query(vector<int>(1, s), v, T);
}

int N, root;
vector<int> parent;
vector<int> subtree_size;

int main() {
    // ios::sync_with_stdio(false);

    cin >> N;
    root = 0;
    parent.assign(N, -1);
    subtree_size.assign(N, -1);
    vector<int> non_root;

    for (int i = 0; i < N; i++)
        if (i != root)
            non_root.push_back(i);

    for (int i = 0; i < N; i++)
        if (i != root)
            subtree_size[i] = query(root, i, non_root);

    subtree_size[root] = N;
    vector<int> sorted;

    for (int i = 0; i < N; i++)
        sorted.push_back(i);

    sort(sorted.begin(), sorted.end(), [&](int a, int b) {
        return subtree_size[a] < subtree_size[b];
    });

    for (int i = 0; i < N; i++) {
        int v = sorted[i];
        vector<int> missing_parent;

        // cerr << "solving " << v + 1 << endl;

        for (int j = 0; j < i; j++)
            if (parent[sorted[j]] < 0)
                missing_parent.push_back(sorted[j]);

        int remaining = query(root, v, missing_parent);
        int high = (int) missing_parent.size() - 1;

        while (remaining > 0) {
            int low = 0;

            while (low < high) {
                int mid = (low + high + 1) / 2;

                if (query(root, v, vector<int>(missing_parent.begin(), missing_parent.begin() + mid)) == remaining)
                    high = mid - 1;
                else
                    low = mid;
            }

            int child = missing_parent[low];
            parent[child] = v;
            remaining--;
            high = low - 1;
            // cerr << "parent of " << child + 1 << " is " << v + 1 << endl;
            // cerr << remaining << " remaining for " << v + 1 << endl;
        }
    }

    cout << "ANSWER" << '\n';

    for (int i = 0; i < N; i++)
        if (parent[i] >= 0)
            cout << i + 1 << ' ' << parent[i] + 1 << '\n';

    cout << flush;
}