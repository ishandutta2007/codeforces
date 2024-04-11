#include <bits/stdc++.h>
using namespace std;

#define DEBUG

namespace debug {
    void dbg(int& x) { cerr << x; }
    void dbg(long &x) { cerr << x; }
    void dbg(long long& x) { cerr << x; }
    void dbg(unsigned& x) { cerr << x; }
    void dbg(unsigned long& x) { cerr << x; }
    void dbg(unsigned long long& x) { cerr << x; }
    void dbg(float& x) { cerr << x; }
    void dbg(double& x) { cerr << x; }
    void dbg(long double& x) { cerr << x; }
    void dbg(char& x) { cerr << x; }
    void dbg(const char* x) { cerr << x; }
    void dbg(string& x) { cerr << x; }

    template <typename A, typename B>
    void dbg(pair<A, B> x);

    template <typename T, size_t N> 
    void dbg(array<T, N>& v);

    template <typename T> 
    void dbg(vector<T>& v);

    template <typename Head, typename... Tail>
    void dbg(Head& H, Tail&... T) {
        dbg(H);
        if (sizeof...(T)) {
            dbg(", ");
        }
        dbg(T...);
    }

    template <typename A, typename B>
    void dbg(pair<A, B> x) {
        cerr << "(", dbg(x.first), cerr << ", ", dbg(x.second), cerr << ")";
    }

    template<typename A, typename B, typename C>
    void dbg(tuple<A, B, C>& x) {
        cerr << "(", dbg(get<0>(x)), cerr << ", ", dbg(get<1>(x)), cerr << ", ", dbg(get<2>(x)), cerr << ")";
    }

    template<typename A, typename B, typename C, typename D>
    void dbg(tuple<A, B, C, D>& x) {
        cerr << "(", dbg(get<0>(x)), cerr << ", ", dbg(get<1>(x)), cerr << ", ", dbg(get<2>(x)), cerr << ", ", dbg(get<2>(x)), cerr << ")";
    }

    template <typename T, size_t N> 
    void dbg(array<T, N>& v) { 
        dbg("{");
        for (int i = 0; i < N; i++) { 
            if (i > 0) dbg(", ");
            dbg(v[i]); 
        }
        dbg("}");
    }    

    template <typename T> 
    void dbg(vector<T>& v) {
        dbg("{");
        for (int i = 0; i < static_cast<int>(v.size()); i++) { 
            if (i > 0) dbg(", ");
            dbg(v[i]); 
        } 
        dbg("}");   
    }

    #ifdef DEBUG
    #define debug(x...) cerr << "[" << #x << "] = [", debug::dbg(x), cerr << "]" << endl
    #else
    #define debug(x...)
    #endif

}

namespace input {
    void read(int& x) { cin >> x; }
    void read(long &x) { cin >> x; }
    void read(long long& x) { cin >> x; }
    void read(unsigned& x) { cin >> x; }
    void read(unsigned long& x) { cin >> x; }
    void read(unsigned long long& x) { cin >> x; }
    void read(float& x) { cin >> x; }
    void read(double& x) { cin >> x; }
    void read(long double& x) { cin >> x; }
    void read(char& x) { cin >> x; }
    void read(string& x) { cin >> x; }
    
    template<typename A, typename B>
    void read(pair<A, B>& x);

    template<typename A, typename B, typename C>
    void read(tuple<A, B, C>& x);

    template<typename A, typename B, typename C, typename D>
    void read(tuple<A, B, C, D>& x);

    template <typename T, size_t N> 
    void read(array<T, N>& v);
    
    template <typename T> 
    void read(vector<T>& v);

    template <typename Head, typename... Tail>
    void read(Head& H, Tail&... T) {
        read(H);
        read(T...);
    }

    template<typename A, typename B>
    void read(pair<A, B>& x) {
        read(x.first, x.second);
    }

    template<typename A, typename B, typename C>
    void read(tuple<A, B, C>& x) {
        read(get<0>(x), get<1>(x), get<2>(x));
    }

    template<typename A, typename B, typename C, typename D>
    void read(tuple<A, B, C, D>& x) {
        read(get<0>(x), get<1>(x), get<2>(x), get<3>(x));
    }

    template <typename T, size_t N> 
    void read(array<T, N>& v) { 
        for (int i = 0; i < N; i++) { 
            read(v[i]); 
        } 
    }    
    
    template <typename T> 
    void read(vector<T>& v) { 
        for (int i = 0; i < static_cast<int>(v.size()); i++) { 
            read(v[i]); 
        } 
    }

    void readln(string& x) {
        getline(cin, x);
    }

};

namespace output {
    void write(int& x) { cout << x; }
    void write(long &x) { cout << x; }
    void write(long long& x) { cout << x; }
    void write(unsigned& x) { cout << x; }
    void write(unsigned long& x) { cout << x; }
    void write(unsigned long long& x) { cout << x; }
    void write(float& x) { cout << x; }
    void write(double& x) { cout << x; }
    void write(long double& x) { cout << x; }
    void write(char& x) { cout << x; }
    void write(const char* x) { cout << x; }
    void write(string& x) { cout << x; }

    template <typename A, typename B>
    void write(pair<A, B>& x);
    
    template<typename A, typename B, typename C>
    void write(tuple<A, B, C>& x);

    template<typename A, typename B, typename C, typename D>
    void write(tuple<A, B, C, D>& x);
    
    template <typename T, size_t N> 
    void write(array<T, N>& v);
    
    template <typename T> 
    void write(vector<T>& v);

    template <typename Head, typename... Tail>
    void write(Head& H, Tail&... T) {
        write(H);
        if (sizeof...(T)) write(" ");
        write(T...);
    }

    template <typename A, typename B>
    void write(pair<A, B>& x) {
        write(x.first, x.second);
    }

    template<typename A, typename B, typename C>
    void write(tuple<A, B, C>& x) {
        write(get<0>(x), get<1>(x), get<2>(x));
    }

    template<typename A, typename B, typename C, typename D>
    void write(tuple<A, B, C, D>& x) {
        write(get<0>(x), get<1>(x), get<2>(x), get<3>(x));
    }

    template <typename T, size_t N> 
    void write(array<T, N>& v) { 
        for (int i = 0; i < N; i++) { 
            if (i > 0) write(" ");
            write(v[i]); 
        } 
    }    
    
    template <typename T> 
    void write(vector<T>& v) { 
        for (int i = 0; i < static_cast<int>(v.size()); i++) { 
            if (i > 0) write(" ");
            write(v[i]); 
        } 
    }

    void writeln() { cout << "\n"; }

    template <typename Head, typename... Tail>
    void writeln(Head& H, Tail&... T) {
        write(H);
        if (sizeof...(T)) {
            write(" ");
        }
        writeln(T...);
    }
    
};

namespace io {
    void fileIn(string s) { freopen((s + ".in").c_str(), "r", stdin); }
    void fileIn(const char* s) { freopen(((string)s + ".in").c_str(), "r", stdin); }
    void fileOut(string s) { freopen((s + ".out").c_str(), "w", stdout); }
    void fileOut(const char* s) { freopen(((string)s + ".out").c_str(), "w", stdout); }
    void fileIO(string s) { fileIn(s), fileOut(s); }
    void fileIO(const char* s) { fileIn(s), fileOut(s); }
    
    void fastIO() {
        ios::sync_with_stdio(0);
        cin.tie(0), cout.tie(0);
    }

};

using namespace input;
using namespace output;
using namespace io;

int main() {
    fastIO();

    int N, M;
    int SR, SC;
    int L, R;
    read(N, M, SR, SC, L, R);
    vector<string> G(N);
    read(G);
    SR--;
    SC--;
    deque<pair<pair<int, int>, pair<int, int>>> dq;
    vector<vector<pair<int, int>>> dist(N, vector<pair<int, int>>(M, {-1, -1}));
    dq.push_back({{SR, SC}, {0, 0}});
    dist[SR][SC] = {0, 0};

    auto inside = [&](int i, int j) {
        if (!(0 <= i && i < N && 0 <= j && j < M)) return false;
        if (dist[i][j] != make_pair(-1, -1)) return false;
        if (G[i][j] == '*') return false;
        return true;
    };

    while (!dq.empty()) {
        pair<int, int> f = dq.front().first;
        pair<int, int> w = dq.front().second;
        dq.pop_front();

        if (inside(f.first + 1, f.second)) 
            dq.push_front({{f.first + 1, f.second}, w}), dist[f.first + 1][f.second] = w;
        if (inside(f.first - 1, f.second)) 
            dq.push_front({{f.first - 1, f.second}, w}), dist[f.first - 1][f.second] = w;
        if (inside(f.first, f.second + 1)) 
            dq.push_back({{f.first, f.second + 1}, {w.first, w.second + 1}}), dist[f.first][f.second + 1] = {w.first, w.second + 1};
        if (inside(f.first, f.second - 1)) 
            dq.push_back({{f.first, f.second - 1}, {w.first + 1, w.second}}), dist[f.first][f.second - 1] = {w.first + 1, w.second};
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dist[i][j] == make_pair(-1, -1)) continue;
            if (dist[i][j].first <= L && dist[i][j].second <= R) {
                ans++;
            }
        }
    }

    writeln(ans);
    return 0;
}