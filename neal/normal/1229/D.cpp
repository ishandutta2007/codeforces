#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int K_MAX = 5;
const int KK_MAX = 2931;
const int MAX_BASIS = 5;

int to_number(int P[K_MAX]) {
    return P[0] + 5 * P[1] + 25 * P[2] + 125 * P[3] + 625 * P[4];
}

void from_number(int number, int P[K_MAX]) {
    P[0] = number % 5; number /= 5;
    P[1] = number % 5; number /= 5;
    P[2] = number % 5; number /= 5;
    P[3] = number % 5; number /= 5;
    P[4] = number;
}

int N, K;
int X[K_MAX], Y[K_MAX];

void apply(int P[K_MAX]) {
    for (int k = 0; k < K; k++)
        Y[k] = X[P[k]];

    for (int k = 0; k < K; k++)
        X[k] = Y[k];
}

int factorial[6] = {1, 1, 2, 6, 24, 120};

struct option {
    bitset<KK_MAX> perms;
    int count = 1;

    int basis[MAX_BASIS][K_MAX];
    int n_basis = 0;

    option() {
        for (int k = 0; k < K; k++)
            X[k] = k;

        perms[to_number(X)] = true;
    }

    void dfs(int number) {
        assert(!perms[number]);
        perms[number] = true;

        for (int i = 0; i < n_basis; i++) {
            from_number(number, X);
            apply(basis[i]);
            int neighbor = to_number(X);

            if (!perms[neighbor])
                dfs(neighbor);
        }
    }

    void add_perm(int P[K_MAX]) {
        if (perms.count() == factorial[K])
            return;

        for (int k = 0; k < K; k++)
            basis[n_basis][k] = P[k];

        n_basis++;
        bool success = false;
        bitset<KK_MAX> original = perms;

        for (int number = original._Find_first(); number < KK_MAX; number = original._Find_next(number)) {
            from_number(number, X);
            apply(P);
            int neighbor = to_number(X);

            if (!perms[neighbor]) {
                success = true;
                dfs(neighbor);
            }
        }

        if (!success)
            n_basis--;
    }
};

int P[K_MAX];
vector<option> options;

void compress_options() {
    int prev_count = 0;
    vector<option> new_options;

    for (option &opt : options) {
        int opt_count = opt.perms.count();

        if (opt_count == prev_count) {
            new_options.back().count += opt.count;
        } else {
            prev_count = opt_count;
            new_options.push_back(opt);
        }
    }

    options = move(new_options);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    long long total = 0;

    while (N-- > 0) {
        for (int k = 0; k < K; k++) {
            cin >> P[k];
            P[k]--;
        }

        options.emplace_back();

        for (option &opt : options)
            opt.add_perm(P);

        compress_options();

        for (option &opt : options)
            total += opt.perms.count() * opt.count;
    }

    cout << total << '\n';
}