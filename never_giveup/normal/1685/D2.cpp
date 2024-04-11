#include <bits/stdc++.h>

namespace std {

    template<class Fun>
    class y_combinator_result {
        Fun fun_;
    public:
        template<class T>
        explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

        template<class ...Args>
        decltype(auto) operator()(Args &&...args) {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
    };

    template<class Fun>
    decltype(auto) y_combinator(Fun &&fun) {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
    }

} // namespace std

int main() {
#ifdef ONPC
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#endif
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        std::vector<int> P(N);
        for (auto& p : P) { cin >> p; p--; }
        //cerr << "Start case" << '\n';
        //for (int p : P) { cerr << p << ' '; } cerr << '\n';

        std::vector<int> par(N, -1);
        auto get_par = [&](int a) {
            while (par[a] >= 0) {
                if (par[par[a]] >= 0) par[a] = par[par[a]];
                a = par[a];
            }
            return a;
        };
        auto merge = [&](int a, int b) {
            a = get_par(a);
            b = get_par(b);
            if (a == b) return false;
            if (par[a] > par[b]) std::swap(a, b);
            par[a] += par[b];
            par[b] = a;
            return true;
        };
        auto reset_par = [&]() {
            for (int i = 0; i < N; i++) par[i] = -1;
        };

        int expect = N - 1;
        reset_par();
        for (int i = 0; i < N; i++) {
            expect -= merge(i, P[i]);
        }

        // we start at the P[0] -> 0 edge
        std::vector<int> Q; Q.reserve(N);
        Q.push_back(0);

        std::vector<bool> used(N);
        used[0] = true;

        std::vector<int> num_up(N-1);
        std::vector<int> num_down(N-1);
        vector<bool> in(N), out(N);

        for (int z = 1; z < N; z++) {
            for (int cnd = 0; true; cnd++) {
                assert(cnd < N);
                if (used[cnd]) continue;
                // get from Q.back() to P[i]
                // just check this scenario in linear time...
                Q.push_back(cnd);
                used[cnd] = true;
                if ([&]() -> bool {
                    //cerr << "checking sequence" << ' '; for (int i : Q) { cerr << P[i] << '-' << i << ' '; } cerr << '\n';

                    for (int i = 0; i + 1 < N; i++) {
                        num_up[i] = num_down[i] = 0;
                    }
                    for (int i = 0; i < N; i++) {
                        in[i] = out[i] = 0;
                    }

                    reset_par();

                    for (int i = 0; i < N; i++) {
                        merge(i, P[i]);
                    }

                    for (int t = 0; t + 1 < int(Q.size()); t++) {
                        int st = Q[t];
                        int en = P[Q[t + 1]];
                        out[st] = 1;
                        in[en] = 1;
                        merge(st, en);
                        if (st < en) {
                            for (int i = st; i + 1 <= en; i++) {
                                if (num_up[i]) return false;
                                num_up[i]++;
                            }
                        } else if (st > en) {
                            for (int i = st; i - 1 >= en; i--) {
                                if (num_down[i - 1]) return false;
                                num_down[i - 1]++;
                            }
                        }
                    }


                    int current = 0;

                    for (int i = 0; i + 1 < N; i++)
                        if (num_up[i] || num_down[i]) {
                            current++;
                            if (num_up[i] ^ num_down[i])
                                merge(i, i + 1);
                        }

                    for (int i = 0; i + 1 < N; i++)
                        if (get_par(i) != get_par(i + 1) &&
                        !num_up[i] && !num_down[i] &&
                        in[i] + out[i] < 2 && in[i + 1] + out[i + 1] < 2)
                            current += merge(i, i + 1);
                    for (int i = 0; i < N; i++)
                        if (get_par(i) != get_par(0))
                            return false;
                    assert(current >= expect);
                    return current == expect;
                }()) {
                    //cerr << "append " << cnd << '\n';
                    break;
                } else {
                    Q.pop_back();
                    used[cnd] = false;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            cout << Q[i]+1 << " \n"[i+1==N];
        }
    }

    return 0;
}