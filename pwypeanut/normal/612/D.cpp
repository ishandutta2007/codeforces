#include <bits/stdc++.h>
using namespace std;

int N, K, cur;
pair<int, int> P[2000005];
vector< pair<int, int> > V, v;
vector<int> v1;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    else return a.second > b.second;
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        P[i*2] = make_pair(a, 1);
        P[i*2+1] = make_pair(b, -1);
    }
    sort(P, P + N * 2, cmp);
    for (int i = 0; i < N * 2; i++) {
        if (cur < K && cur + P[i].second >= K) {
            v1.push_back(P[i].first);
        } else if (cur >= K && cur + P[i].second < K) {
            v1.push_back(P[i].first);
        }
        cur += P[i].second;
    }
    if (v1.size() == 0) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < v1.size(); i+=2) {
        v.push_back(make_pair(v1[i], v1[i+1]));
    }
    int last = v[0].first;
    for (int i = 0; i < v.size(); i++) {
        if (i + 1 == v.size() || v[i].second != v[i+1].first) {
            V.push_back(make_pair(last, v[i].second));
            if (i + 1 != v.size()) last = v[i+1].first;
        }
    }
    printf("%d\n", V.size());
    for (int i = 0; i < V.size(); i++) printf("%d %d\n", V[i].first, V[i].second);
}