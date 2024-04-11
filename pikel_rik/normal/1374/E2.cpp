#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int n, m, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;

    vector<pair<int, int>> a1(1), a2(1), a3(1), a4(1);
    for (int i = 0; i < n; i++) {
        int t, a, b;
        cin >> t >> a >> b;

        if (!a and !b)
            a4.emplace_back(t, i + 1);
        else if (a and b)
            a1.emplace_back(t, i + 1);
        else if (a)
            a2.emplace_back(t, i + 1);
        else a3.emplace_back(t, i + 1);
    }

    if (a1.size() + a2.size() < k + 2 or a1.size() + a3.size() < k + 2) {
        cout << "-1\n";
        return 0;
    }

    ordered_set<pair<int, int>> s;
    for (int i = 1; i < a4.size(); i++)
        s.insert(a4[i]);
    for (int i = 1; i < a1.size(); i++)
        s.insert(a1[i]);

    sort(all(a1));
    sort(all(a2));
    sort(all(a3));

    for (int i = k + 1; i < a2.size(); i++)
        s.insert(a2[i]);

    for (int i = k + 1; i < a3.size(); i++)
        s.insert(a3[i]);

    ordered_set<pair<int, int>> temp = s;

    for (int i = 1; i < a1.size(); i++)
        a1[i].first += a1[i - 1].first;

    for (int i = 1; i < a2.size(); i++)
        a2[i].first += a2[i - 1].first;

    for (int i = 1; i < a3.size(); i++)
        a3[i].first += a3[i - 1].first;

    int best = inf;
    int sum = 0;

    for (int i = 0; i < a1.size(); i++) {
        int req = m - (k + k - i);
        if (sum == 0) {
            for (int j = 0; j < req; j++)
                sum += (*s.find_by_order(j)).first;
        }

        if (i > 0) {
            pair<int, int> p = {a1[i].first - a1[i - 1].first, a1[i].second};

            s.erase(p);
            if ((int)s.order_of_key(p) < req) {
                sum -= p.first;
                sum += (*s.find_by_order(req - 1)).first;
            }
        }

        if (k - i < a2.size() and k - i < a3.size() and k - i >= 0 and k + k - i <= m) {
            best = min(best, sum + a1[i].first + a2[k - i].first + a3[k - i].first);
//            cout << sum + a1[i].first + a2[k - i].first + a3[k - i].first << " ";
        }

        if (req >= 0)
            sum += (*s.find_by_order(req)).first;

        if (k - i > 0) {
            if (k - i < a2.size()) {
                pair<int, int> p = {a2[k - i].first - a2[k - i - 1].first, a2[k - i].second};
                s.insert(p);
                if ((int)s.order_of_key(p) <= req) {
                    sum += p.first;
                    sum -= (*s.find_by_order(req + 1)).first;
                }
            }

            if (k - i < a3.size()) {
                pair<int, int> p = {a3[k - i].first - a3[k - i - 1].first, a3[k - i].second};
                s.insert(p);
                if ((int)s.order_of_key(p) <= req) {
                    sum += p.first;
                    sum -= (*s.find_by_order(req + 1)).first;
                }
            }
        }
    }

    if (best == inf) {
        cout << "-1\n";
        return 0;
    }

    s = temp;
    sum = 0;

    for (int i = 0; i < a1.size(); i++) {
        int req = m - (k + k - i);
        if (sum == 0) {
            for (int j = 0; j < req; j++)
                sum += (*s.find_by_order(j)).first;
        }

        if (i > 0) {
            pair<int, int> p = {a1[i].first - a1[i - 1].first, a1[i].second};

            s.erase(p);
            if ((int)s.order_of_key(p) < req) {
                sum -= p.first;
                sum += (*s.find_by_order(req - 1)).first;
            }
        }

        if (k - i < a2.size() and k - i < a3.size() and k - i >= 0 and k + k - i <= m) {
            if (best == sum + a1[i].first + a2[k - i].first + a3[k - i].first) {
                cout << best << "\n";
                for (int j = 1; j <= i; j++)
                    cout << a1[j].second << " ";
                for (int j = 1; j <= k - i; j++)
                    cout << a2[j].second << " ";
                for (int j = 1; j <= k - i; j++)
                    cout << a3[j].second << " ";
                for (int j = 0; j < req; j++)
                    cout << (*s.find_by_order(j)).second << " ";
                return 0;
            }
        }

        if (req >= 0)
            sum += (*s.find_by_order(req)).first;
        if (k - i > 0) {
            if (k - i < a2.size()) {
                pair<int, int> p = {a2[k - i].first - a2[k - i - 1].first, a2[k - i].second};
                s.insert(p);
                if ((int)s.order_of_key(p) <= req) {
                    sum += p.first;
                    sum -= (*s.find_by_order(req + 1)).first;
                }
            }

            if (k - i < a3.size()) {
                pair<int, int> p = {a3[k - i].first - a3[k - i - 1].first, a3[k - i].second};
                s.insert(p);
                if ((int)s.order_of_key(p) <= req) {
                    sum += p.first;
                    sum -= (*s.find_by_order(req + 1)).first;
                }
            }
        }
    }
    return 0;
}