#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef long long ll;

int K, M, m, n, f[200005], a[200005], b[200005];
pair<int, int> k[200005];
multiset<int> chosen, notchosen;
int sum, confirmed;
vector<pair<int, int> > avail;

pair<int, int> comp(vector<tuple<int, int, int> > tmp) {
	int r1 = 0, r2 = 0, curr = 0;
	vector<tuple<int, int, int> > ev;
	for (auto i : tmp) r2 += get<2>(i);
	for (auto [l, r, v] : tmp) {
		ev.emplace_back(l, 0, v);
		ev.emplace_back(r, 1, -v);
	}
	sort(ev.begin(), ev.end());
	for (auto [p, t, v] : ev) {
		curr += v;
		r1 = max(r1, curr);
	}
	return make_pair(r1, r2);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> K >> M;
	m = 1;
	for (int i = 1; i <= K; i++) {
		cin >> k[i].second;
		if (i == 1) k[i].first = 0;
		else k[i].first = (i - 1) * 100;
	}
	sort(k + 1, k + 1 + K);
	for (int i = 1; i <= M; i++) cin >> f[i];
	sort(f + 1, f + 1 + M);
	int pt = 1;
	f[0] = -1e9;
	for (int i = 1; i <= M; i++) {
		vector<tuple<int, int, int> > tmp;
		while (pt <= K && k[pt].first < f[i]) {
			int rad = min(k[pt].first - f[i - 1] - 1, f[i] - k[pt].first - 1);
			tmp.emplace_back(k[pt].first - rad - 1, k[pt].first + rad, k[pt].second);
			pt++;
		}
		auto res = comp(tmp);
		n++;
		avail.emplace_back(-res.first, res.first - res.second);
	}
	vector<tuple<int, int, int> > tmp;
	while (pt <= K) {
		int rad = k[pt].first - f[M] - 1;
		tmp.emplace_back(k[pt].first - rad - 1, k[pt].first + rad, k[pt].second);
		pt++;
	}
	auto res = comp(tmp);
	n++;
	avail.emplace_back(-res.first, res.first - res.second);
    sort(avail.begin(), avail.end(), [](pair<int, int> a, pair<int, int> b){
        return a.first + a.second < b.first + b.second;
    });
    for (int i = 0; i < n; i++){
        if (chosen.size() < m){
            chosen.insert(avail[i].first);
            sum += avail[i].first;
        } else {
            auto itr = --chosen.end();
            if (avail[i].first >= *itr){
                notchosen.insert(avail[i].first);
            } else {
                notchosen.insert(*itr);
                sum -= *itr;
                chosen.erase(itr);
                sum += avail[i].first;
                chosen.insert(avail[i].first);
            }
        }
    }
    int ans = 1e15;
    if (m == chosen.size()) ans = min(ans, sum);
    for (int i = 0; i < n; i++){
        if (confirmed == m) continue;
        int musttake = avail[i].first;
        auto itr = chosen.find(musttake);
        if (itr == chosen.end()){
            notchosen.erase(notchosen.find(musttake));
            sum += musttake;
        } else {
            chosen.erase(itr);
        }
        confirmed++;
        if (chosen.size() > m - confirmed){
            auto itr = --chosen.end();
            notchosen.insert(*itr);
            sum -= *itr;
            chosen.erase(itr);
        }
        if (chosen.size() < m - confirmed){
            chosen.insert(avail[i].second);
            sum += avail[i].second;
        } else if (confirmed != m){
            auto itr = --chosen.end();
            if (avail[i].second >= *itr){
                notchosen.insert(avail[i].second);
            } else {
                notchosen.insert(*itr);
                sum -= *itr;
                chosen.erase(itr);
                sum += avail[i].second;
                chosen.insert(avail[i].second);
            }
        }
        if (chosen.size() + confirmed == m) ans = min(ans, sum);
    }
    cout << -ans << '\n';
}