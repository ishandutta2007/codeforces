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

    int N;
    read(N);
    int INF = 1e9;
    int le = -INF + 2;
    int ri = +INF;

    cout << "1 " << INF << endl;
    string cmp;
    cin >> cmp;

    for (int i = 1; i < N; i++) {
        int mid = floor((1.00 * ri + le) / 2.00);
        if (mid >= 0) {
            cout << INF << " " << INF - mid << endl;
        } else {
            cout << INF + mid << " " << INF << endl;
        }
        
        string in;
        read(in);
        // in = "black";
        if (in != cmp) {
            ri = mid - 1;
        } else {
            le = mid + 1;
        }
    }
    assert(le <= ri);
    int mid = floor((1.00 * ri + le) / 2.00);
    if (mid >= 0) {
        cout << INF << " " << INF - mid;
    } else {
        cout << INF + mid << " " << INF;
    }
    
    cout << " 0 0" << endl;
    return 0;
}