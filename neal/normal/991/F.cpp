#include <cmath>
#include <iostream>
#include <string>
using namespace std;

long long N;
string best;

long long get_power(long long a, long long b) {
    long long p = 1;

    while (b--)
        p *= a;

    return p;
}

int get_length(long long n) {
    int count = 0;

    do {
        count++;
        n /= 10;
    } while (n > 0);

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    best = to_string(N);

    // a^b * c + d
    for (long long b = 2; pow(2, b) <= 1e18; b++)
        for (long long a = 2; pow(a, b) <= 1e18 && get_power(a, b) <= N; a++) {
            long long c = N / get_power(a, b);
            long long d = N - c * get_power(a, b);
            string candidate = to_string(a) + "^" + to_string(b);

            if (c > 1)
                candidate += "*" + to_string(c);

            if (d > 0)
                candidate += "+" + to_string(d);

            if (candidate.size() < best.size())
                best = candidate;
        }

    // a^b + c^d * e + f
    for (long long b = 2; pow(2, b) <= 1e18; b++)
        for (long long a = 2; a < 1000 && pow(a, b) <= 1e18 && get_power(a, b) <= N; a++) {
            long long p = get_power(a, b);

            for (long long d = 2; p + pow(2, d) <= N; d++)
                for (long long c = 2; c < (a >= 100 ? 10 : 100) && p + pow(c, d) <= 1e18 && p + get_power(c, d) <= N; c++) {
                    long long p2 = get_power(c, d);
                    long long e = (N - p) / p2;
                    long long f = N - p - p2 * e;

                    int length = get_length(a) + get_length(b) + get_length(c) + get_length(d) + 3;

                    if (length >= (int) best.size())
                        continue;

                    if (e > 1)
                        length += get_length(e) + 1;

                    if (f > 0)
                        length += get_length(f) + 1;

                    if (length < (int) best.size()) {
                        string candidate = to_string(a) + "^" + to_string(b) + "+" + to_string(c) + "^" + to_string(d);

                        if (e > 1)
                            candidate += "*" + to_string(e);

                        if (f > 0)
                            candidate += "+" + to_string(f);

                        if (candidate.size() < best.size())
                            best = candidate;
                    }
                }
        }

    // a^b * c^d * e + f
    for (long long b = 2; pow(2, b) <= 1e18; b++)
        for (long long a = 2; a < 1000 && pow(a, b) <= 1e18 && get_power(a, b) <= N; a++) {
            long long p = get_power(a, b);

            for (long long d = 2; p * pow(2, d) <= N; d++)
                for (long long c = 2; c < (a >= 100 ? 10 : 100) && p * pow(c, d) <= 1e18 && p * get_power(c, d) <= N; c++) {
                    long long pp = p * get_power(c, d);
                    long long e = N / pp;
                    long long f = N - pp * e;

                    int length = get_length(a) + get_length(b) + get_length(c) + get_length(d) + 3;

                    if (length >= (int) best.size())
                        continue;

                    if (e > 1)
                        length += get_length(e) + 1;

                    if (f > 0)
                        length += get_length(f) + 1;

                    if (length < (int) best.size()) {
                        string candidate = to_string(a) + "^" + to_string(b) + "*" + to_string(c) + "^" + to_string(d);

                        if (e > 1)
                            candidate += "*" + to_string(e);

                        if (f > 0)
                            candidate += "+" + to_string(f);

                        if (candidate.size() < best.size())
                            best = candidate;
                    }
                }
        }

    cout << best << '\n';
    return 0;
}