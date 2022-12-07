#include<bits/stdc++.h>

using namespace std;

const int N = 300030;
typedef pair  < pair < int, int >, int > interval;

int n, k;
int cont[N];
pair < int, int > a[N];
vector < pair < int, int > > changes[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("inp", "r")) freopen("inp", "r", stdin);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    set < interval > segs;
    for(int i = 1; i <= n; ++i) {
        interval p = make_pair(make_pair(a[i].first, -1), -1);
        while(true) {
            auto it = segs.lower_bound(p);
            if(it != segs.begin()) {
                --it;
                if(it -> first.second <= p.first.first) ++it;
            }
            if(it == segs.end() || it -> first.first >= a[i].second) break;
            auto q = *it;
            segs.erase(it);
            changes[i].emplace_back(q.second, -min(q.first.second, a[i].second) + max(q.first.first, a[i].first));
            if(q.first.first >= a[i].first && q.first.second <= a[i].second) continue;
            if(q.first.first <= a[i].first && q.first.second >= a[i].second) {
                interval x = q, y = q;
                x.first.second = a[i].first;
                y.first.first = a[i].second;
                if(x.first.first < x.first.second) segs.insert(x);
                if(y.first.first < y.first.second) segs.insert(y);
                continue;
            }
            if(q.first.first <= a[i].first) {
                q.first.second = a[i].first;
            }
            else {
                q.first.first = a[i].second;
            }
            if(q.first.second > q.first.first) segs.insert(q);
        }
        segs.emplace(make_pair(a[i], i));
        changes[i].emplace_back(i, a[i].second - a[i].first);
    }

    auto calc = [&](int val) -> pair < long long, long long > {
        int pos = 0, sum_length = 0;
        long long sum = 0, sum2 = 0;
        memset(cont, 0, sizeof cont);
        pair < long long, long long > ret = make_pair(0, 0);

        for(int i = 1; i <= n; ++i) {
            for(auto c : changes[i]) {
                cont[c.first] += c.second;
                if(c.first >= pos) {
                    sum_length += c.second;
                }
                else {
                    sum2 += c.second;
                    sum += 1LL * c.second * c.first;
                }
            }

            while(sum_length - cont[pos] >= val) {
                sum_length -= cont[pos];
                sum += 1LL * cont[pos] * pos;
                sum2 += cont[pos];
                ++pos;
            }

            ret.first += pos;
            ret.second += 1LL * pos * sum_length + sum;
        }
        return ret;
    };

    int low = 1, high = (int)1e9, ans = 0;
    while(low <= high) {
        int mid = (low + high) >> 1;
        if(calc(mid).first >= k) {
            low = mid + 1;
            ans = mid;
        }
        else {
            high = mid - 1;
        }
    }

    auto p = calc(ans + 1);
    cout << p.second + 1LL * (k - p.first) * ans << endl;

    return 0;
}