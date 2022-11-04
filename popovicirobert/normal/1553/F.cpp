#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";
 
using namespace std;

constexpr int MAXVAL = (int)3e5;
constexpr int BUCK = 200;

struct Node {
    ll sum;
    int cnt;

    Node() : sum(0), cnt(0) {}

    Node(ll sum, int cnt) : sum(sum), cnt(cnt) {}
};

template<typename T,
         typename Func = std::function<T(const T&, const T&)>,
         typename Alloc = std::vector<T>>
class Fenwick {
public:
    Fenwick() {}
    Fenwick(int n) : n(n) {
        combine = [](const T& a, const T& b) { return a + b; };
        data.resize(n + 1);
    }
    Fenwick(int n, const Func& func) : n(n), combine(func) {
        data.resize(n + 1);
    }
    Fenwick(int n, Func&& func) : n(n), combine(std::move(func)) {
        data.resize(n + 1);
    }
    ~Fenwick() {
        data.clear();
    }

    void init(int _n, const T& t = T()) {
        n = _n;
        data.resize(n + 1, t);
    }
    void set(const T& t) {
        fill(data.begin(), data.end(), t);
    }
    
    T get(int pos) {
        assert(pos <= n && pos >= 1);
        return data[pos];
    }

    const T& get(int pos) const {
        assert(pos <= n && pos >= 1);
        return data[pos];
    }

    void update_prefix(int pos, const T& t) {
        assert(pos <= n && pos >= 1);

        for (int i = pos; i <= n; i += lsb(i)) {
            data[i] = std::move(combine(data[i], t));
        }
    }
    void update_suffix(int pos, const T& t) {
        assert(pos <= n && pos >= 1);

        for (int i = pos; i > 0; i -= lsb(i)) {
            data[i] = std::move(combine(data[i], t));
        }
    }

    T query_prefix(int pos) {
        assert(pos <= n);

        T answer = T();
        for (int i = pos; i > 0; i -= lsb(i)) {
            answer = std::move(combine(answer, data[i]));
        }
        return answer;
    }
    T query_suffix(int pos) {
        assert(pos <= n && pos >= 1);

        T answer = T();
        for (int i = pos; i <= n; i += lsb(i)) {
            answer = std::move(combine(answer, data[i]));
        }
        return answer;
    }

private:
    int n;
    Alloc data;
    Func combine;
};


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    auto combine = [&](const Node& a, const Node& b) {
        return Node(a.sum + b.sum, a.cnt + b.cnt);
    };

    Fenwick<Node, decltype(combine)> fen(MAXVAL + 1, combine);
    ll answer = 0;

    auto easy = [&](int x) {
        for (int i = 0; i <= MAXVAL; i += x) {
            auto curr2 = fen.query_prefix(min(i + x - 1, MAXVAL));
            auto curr1 = fen.query_prefix(i);
            answer += curr2.sum - curr1.sum - 1LL * i * (curr2.cnt - curr1.cnt);
        }
    };  

    vector<bool> vis(MAXVAL + 1);

    auto hard = [&](int x) {
        int num = 1;
        while (x / num > BUCK) {
            if (vis[num]) {
                answer += x % num;
            }
            num++;
        }

        for (int i = min(BUCK, x); i >= 0; i--) {
            // y = ?
            // i <= x / y < i + 1
            int yr = (i == 0 ? MAXVAL : x / i);
            int yl = max(1, x / (i + 1));
            while (x / yl >= i + 1) {
                yl++;
            }

            auto curr2 = fen.query_prefix(yr);
            auto curr1 = fen.query_prefix(yl - 1);

            ll sum = curr2.sum - curr1.sum;
            int cnt = curr2.cnt - curr1.cnt;

            answer += 1LL * x * cnt - 1LL * sum * i;
        }
    };

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        easy(x);
        hard(x);

        fen.update_prefix(x, {x, 1});
        vis[x] = true;

        cout << answer << " ";
    }
    

    return 0;
}