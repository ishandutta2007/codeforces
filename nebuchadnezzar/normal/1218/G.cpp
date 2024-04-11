// Dmitry _kun_ Sayutin (2019)

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;
using std::swap;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

struct edge_t {
    int to;
    int& w;
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    int m = input<int>();

    string s = input<string>();

    vector<vector<edge_t>> graph(n);
    vector<int> answers(m);
    for (int i = 0; i != m; ++i) {
        int v = input<int>();
        int u = input<int>();

        graph[v].push_back(edge_t {u, answers[i]});
        graph[u].push_back(edge_t {v, answers[i]});
    }

    vector<char> color(n, -1);
    std::function<void(int, int)> dfs = [&](int v, int c) {
        color[v] = c;
        
        for (auto u: graph[v])
            if (color[u.to] == -1)
                dfs(u.to, c ^ 1);
    };
    
    dfs(0, 0);
    auto color2 = color;
    
    pair<int, int> fail_at = {-1, -1};
    int* fail_w = nullptr;
    for (int v = 0; v != n; ++v)
        for (auto u: graph[v])
            if (color[u.to] == color[v]) {
                fail_at = {v, u.to};
                fail_w = &u.w;
            }
    
    auto greedy = [&]() {
        vector<int> current(n, 0);
        
        if (fail_at != pair<int, int> {-1, -1}) {
            int sm = 0;
            for (int i = 0; i != n; ++i)
                if (color2[i] == 0)
                    sm += (s[i] - 'X');
                else
                    sm -= (s[i] - 'X');

            sm %= 3;

            for (*fail_w = 1; *fail_w <= 3; ++(*fail_w)) {
                int new_sm = sm;
                
                if (color2[fail_at.first] == 0)
                    new_sm -= 2 * (*fail_w);
                else
                    new_sm += 2 * (*fail_w);

                if (new_sm % 3 == 0)
                    break;
            }

            assert(*fail_w != 4);
            current[fail_at.first] += (*fail_w);
            current[fail_at.second] += (*fail_w);
        }
        
        vector<char> used(n, 0);
        
        std::function<void(int, int)> dfs = [&](int v, int p) {
            used[v] = 1;
            
            for (auto e: graph[v])
                if (used[e.to] == 0) {
                    dfs(e.to, v);

                    e.w = (3 + color[e.to] - current[e.to]) % 3;
                    if (e.w == 0)
                        e.w = 3;
                    current[e.to] = (current[e.to] + e.w) % 3;
                    current[v] = (current[v] + e.w) % 3;
                } else if (used[e.to] == 1 and e.to != p and e.w == 0) {
                    e.w = 3;
                }
            
            used[v] = 2;
        };
        
        dfs(0, -1);
        for (int v = 0; v != n; ++v)
            assert(current[v] == color[v]);
    };
    
    if (fail_at.first == -1) {
        // kukareku
        int n0 = std::count(ALL(color), 0);
        int n1 = std::count(ALL(color), 1);

        if (n0 < 2) {
            swap(n0, n1);
            for (char& elem: color)
                elem ^= 1;
        }

        assert(n0 >= 2);
        for (char& elem: color)
            if (elem == 1)
                elem = 2;
        
        int delta = ((0 * n0 - 2 * n1) % 3 + 3) % 3;
        
        for (int i = 0; i < (3 - delta) % 3; ++i)
            *std::find(ALL(color), 0) = 1;

        greedy();
    } else {
        // 3-kukareku

        for (int i = 0; i != SZ(color); ++i)
            color[i] = s[i] - 'X';

        greedy();
    }
    
    for (int v = 0; v != n; ++v)
        for (auto e: graph[v])
            if (v < e.to)
                cout << v << " " << e.to << " " << e.w << "\n";
    
    return 0;
}