#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };

struct safe_hash32 {
    static unsigned hash32(unsigned x) {
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        return x ^ (x >> 16);
    }

    unsigned operator()(unsigned x) const {
        static const unsigned FIXED_RANDOM = hash32(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
        return hash32(x ^ FIXED_RANDOM);
    }
};

int N, M;
vector<gp_hash_table<int, null_type, safe_hash32>> edges;

bool is_one_edge(int a, int b) {
    if (a > b) swap(a, b);
    return edges[a].find(b) != edges[a].end();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    edges.assign(N, {});

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (a > b) swap(a, b);
        edges[a].insert(b);
    }

    gp_hash_table<int, null_type, safe_hash32> remaining;

    for (int i = 0; i < N; i++)
        remaining.insert(i);

    int components = 0;

    for (int i = 0; i < N; i++)
        if (remaining.find(i) != remaining.end()) {
            remaining.erase(i);
            vector<int> mine = {i};

            for (int index = 0; index < (int) mine.size(); index++) {
                int x = mine[index];
                vector<int> to_erase;

                for (int y : remaining)
                    if (!is_one_edge(x, y)) {
                        mine.push_back(y);
                        to_erase.push_back(y);
                    }

                for (int y : to_erase)
                    remaining.erase(y);
            }

            components++;
        }

    cout << components - 1 << '\n';
}