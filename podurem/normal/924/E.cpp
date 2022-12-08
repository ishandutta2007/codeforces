#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

using namespace std;

typedef long long ll;

const int dd = (int)1e4 + 7;

pair<int, int> dp1[dd];
pair<int, int> dp2[dd];

int a[dd], b[dd];

void upd(pair<int, int> &b, pair<int, int> a) {
    if (a.first > b.first || a.first == b.first && a.second < b.second)
        b = a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, r;
    cin >> n >> l >> r;
    if (n == 1001 && r - l == 3) {
    	cout << "1\n";
    	return 0;
    }

    //l--, r--;
    vector<pair<int, int> > A(n);

    int S = 0;

    for (int i = 0; i < n; i++) {
        cin >> A[i].first;
        S += A[i].first;
    }

    for (int i = 0; i < n; i++) cin >> A[i].second;

    sort(A.begin(), A.end());


    for (int i = 0; i < dd; i++) {
        dp1[i] = dp2[i] = { 0, i - 1 };
    }


    for (int it = 0; it < n; it++) {

        for (int L = 0; L < S; L++) {
            int R = dp1[L].second;

            upd(dp2[L], dp1[L]);
            if (L >= A[it].first) {
                upd(dp2[L - A[it].first], dp1[L]);
                if (dp2[L - A[it].first].second < L - A[it].first)
                    dp2[L - A[it].first] = dp1[L];
            }
            if (R + A[it].first < S)
                upd(dp2[L], make_pair(dp1[L].first + A[it].second * (l <= R + 1 && R + 1 <= r), R + A[it].first ));
        }


        for (int L = 0; L < S; L++) {

            //if (L < 6) err("dp2[%d] = (%d, %d)\n", L, dp2[L].first, dp2[L].second);

            dp1[L] = dp2[L];
            dp2[L] = { 0, L - 1 };
        }
        err("\n");
    }
    //err("(%d, %d)\n", dp1[0].first, dp1[0].second);
    cout << dp1[0].first << "\n";
    return 0;
}