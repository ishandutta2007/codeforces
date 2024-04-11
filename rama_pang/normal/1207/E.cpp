/**
 * Somehow picking A = 0...99 combined brute forcing B gives
 * a correct solution.
 * 
 * Brute forcing B is basically trying all possible numbers, and
 * A[i] ^ new is already encountered, then do not pick that number.
 * Since if for all pairs i, j, A[i] ^ B[j] is unique, we can find
 * the answer.
 * 
 * If we randomly input A, in some cases there isn't a valid B. I
 * suppose since 0...99 only uses very little digits (in binary),
 * this gives an optimal solution?
*/

#include <bits/stdc++.h>
// #define LOCAL

using namespace std;
constexpr int MOD = 1 << 14;

mt19937 rnd(chrono::high_resolution_clock().now().time_since_epoch().count());


int SECRET = (rnd() + MOD) % MOD;

vector<int> used(MOD);

int query(vector<int> A) {
  #ifdef LOCAL
    return A[rnd() % 100] ^ SECRET;
  #else
    cout << "?";
    for (int i = 0; i < 100; i++) {
        cout << " " << A[i];
    }
    cout << endl;
    int in;
    cin >> in;
    return in;
  #endif
}

int main() {
    vector<int> A(100), B(100);
    int a, b;
    for (int i = 0; i < 100; i++) {
        A[i] = i;
        used[A[i]] = 1;
    }

    a = query(A);

    unordered_map<int, int> freq, global;
    for (int i = 0; i < 100; i++) {
        global[(A[i] ^ a)] = 1;
    }
    
    int off = 0;
    for (int i = 0; i < 100; i++) {
        B[i] = -1;
        for (int j = 0; j < MOD; j++) {
            if (used[j]) continue;
            freq.clear();
            bool can = true;
            for (int k = 0; k < 100; k++) {
                if (freq.count((j ^ A[k])) == 1) {
                    can = false;
                    break;
                }
                if (global.count((j ^ A[k])) == 1) {
                    can = false;
                    break;
                }
                freq[(j ^ A[k])] = 1;
            }

            if (can) {
                for (auto f : freq) {
                    global[f.first] = 1;
                }
                B[i] = j;
                used[j] = 1;
                break;
            }
        }

        if (B[i] == -1) {
            int k = rnd() % MOD;
            if (k < 0) k += MOD;
            while (used[k]) {
                k = rnd() % MOD;
                if (k < 0) k += MOD;
            }
            B[i] = k;
            off++;
        }
    }

    b = query(B);

    vector<int> ans;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if ((A[i] ^ a) == (B[j] ^ b)) {
                ans.emplace_back(A[i] ^ a);
            }
        }
    }

  #ifdef LOCAL
    cout << "SECRET: " << SECRET << "\n";
    cout << "GUESS: " << a << " " << b << "\n";
    cout << "OFF: " << off << "\n";
    cout << ans.size() << "\n";
  #endif
    cout << "! " << ans[rnd() % ans.size()] << endl;
    return 0;
}