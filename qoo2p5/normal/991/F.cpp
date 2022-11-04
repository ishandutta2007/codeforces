#include <bits/stdc++.h>

using namespace std;

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

int len(long long x) {
    int result = 0;
    while (x > 0) {
        x /= 10;
        result++;
    }
    return result;
}

map<long long, int> dp;
map<long long, string> repr;

int get(long long x) {
    if (!dp.count(x)) {
        return len(x);
    }
    return dp[x];
}

string get_repr(long long x) {
    if (!repr.count(x)) {
        return to_string(x);
    }
    return repr[x];
}

void run() {
    long long n;
    cin >> n;

    int answer = len(n);
    string expression = to_string(n);

    for (long long a = 2; a <= 100000; a++) {
        long long power = a;
        for (long long b = 2; b <= 100; b++) {
            power *= a;
            if (power > n) {
                break;
            }

            if (len(a) + 1 + len(b) < get(power)) {
                dp[power] = len(a) + 1 + len(b);
                repr[power] = to_string(a) + "^" + to_string(b);
            }

            int mem = get(power);
            string memr = get_repr(power);

            for (long long wtf = 2; wtf <= 50; wtf++) {
                if (wtf * power > n) {
                    break;
                }

                int current = len(wtf) + 1 + mem;
                if (current < get(wtf * power)) {
                    dp[wtf * power] = current;
                    repr[wtf * power] = to_string(wtf) + "*" + memr;
                }
            }
        }
    }

    for (long long a = 2; a <= 100000; a++) {
        long long power = a;
        for (long long b = 2; b <= 100; b++) {
            power *= a;
            if (power > n) {
                break;
            }

            long long coef = n / power;
            long long add = n % power;

            int current = len(a) + len(b) + 1;
            if (coef != 1) {
                current += get(coef) + 1;
            }
            if (add != 0) {
                current += get(add) + 1;
            }

            if (current < answer) {
                answer = current;
                expression = "";
                if (coef != 1) {
                    expression += get_repr(coef) + "*";
                }
                expression += to_string(a) + "^" + to_string(b);
                if (add != 0) {
                    expression += "+" + get_repr(add);
                }
            }
        }
    }

    cerr << answer << "\n";
    cout << expression << "\n";
}