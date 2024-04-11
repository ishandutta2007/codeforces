#include <bits/stdc++.h>
#define debug(x) cerr << ">>>> " << #x << " is " << x << endl
#define testcase int TESTCASE; cin >> TESTCASE; while (TESTCASE--)
using namespace std;
using lint = long long;
using loat = long double;

const lint MOD = (lint)1e9 + 7;
const loat PI = cos((loat)-1);

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M; cin >> N >> M;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }    
    lint sum = 0;
    lint penalty = 0;
    vector<lint> ans(N + 2);
    sort(A.begin() + 1, A.end());
    int cur = 1;
    vector<lint> no(N + 2);
    vector<lint> pref(N + 2);
    vector<lint> pref2(N + 2);
    for (int i = 1; i <= N; i++) {
        pref[i] = pref[i - 1] + A[i];
    }

    for (int i = 1; i <= N; i++) {
        pref2[i] = ((i >= M)? pref2[i - M] : 0) + pref[i];
    }

    for (int i = 1; i <= N; i++) {
        ans[i] = pref2[i];
        // for (int j = i; j >= 0; j -= M) {
        //     ans[i] += pref[j];
        // }
    }


    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " \n"[i == N];
    }

    return 0;
}