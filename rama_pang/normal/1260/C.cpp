#include <bits/stdc++.h>
#define TESTCASE
using namespace std;
using lint = long long;

lint gcd(lint a, lint b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return gcd(b, a % b);
}
/*
RBRBRBBRRRRRB
0123456789
B.....B
R.R.R.R
B...B
R.R.R

pick biggest for ambigous fence
RBBBBBBBBBBR


*/
void solve() {

    lint R, B, K;
    cin >> R >> B >> K;
    // R = rand() % 10;
    // B = rand() % 800;
    // K = rand() % 800;
    // if (K <= 1) K = 2;
    // if (rand() % 3 == 0) B = rand() * R;



    if (R < B) swap(R, B);
    lint G = gcd(R, B);    

    R /= G;
    B /= G;
    // if (R == B) {
    //     cout << "OBEY\n";
    //     return;
    // }
    // cout << "INPUT " << R << " " << B << " " << K << "\n";

        if (ceil(((double)R - 1) / B) >= K) {
            cout << "REBEL\n";
        } else {
            cout << "OBEY\n";
        }
    


    // vector<int> A;
    // for (int i = 0; i < 100000; i++) {
    //     if (i % R == 0) {
    //         A.emplace_back(1);
    //     } else if (i % B == 0) {
    //         A.emplace_back(0);
    //     }
    // }

    // for (int i = 0; i < A.size(); i++) {
    //     if (i + K >= A.size()) break;
    //     int cnt = 0;
    //     for (int j = 0; j < K; j++) {
    //         cnt += A[i + j];
    //     }
    //     if (cnt == 0 || cnt == K) {
    //         // cout << A[i] << " ";
    //         cout << "REBEL\n";
    //         return;
    //     }
    // }
    // cout << "OBEY\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tc = 1;

    #ifdef TESTCASE
    cin >> tc;
    #endif
    
    while (tc--) {
        solve();
    }
}