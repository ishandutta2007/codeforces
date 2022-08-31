#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };

uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

const uint64_t FIXED_RANDOM = splitmix64(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

template<typename T>
struct array_hash {
    using hash_t = uint64_t;

    int n;
    vector<T> arr;
    hash_t hash;

    array_hash(int _n = 0) {
        init(_n);
    }

    array_hash(const vector<T> &_arr) {
        init(_arr);
    }

    hash_t get_hash(int index) const {
        assert(0 <= index && index < n);
        // This ties arr[index] closely with index and ensures we call splitmix64 in between any two arithmetic operations.
        return splitmix64(arr[index] ^ splitmix64(index ^ FIXED_RANDOM));
    }

    void compute_hash() {
        hash = 0;

        for (int i = 0; i < n; i++)
            hash += get_hash(i);
    }

    void init(int _n) {
        n = _n;
        arr.assign(n, 0);
        compute_hash();
    }

    void init(const vector<T> &_arr) {
        arr = _arr;
        n = int(arr.size());
        compute_hash();
    }

    const T& operator[](int index) const {
        return arr[index];
    }

    void modify(int index, const T &value) {
        hash -= get_hash(index);
        arr[index] = value;
        hash += get_hash(index);
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    using hash_t = uint64_t;

    int N;
    cin >> N;
    array_hash<int> freq(N + 1);
    vector<hash_t> hashes(N + 1);
    gp_hash_table<hash_t, int> hash_freq;
    hashes[0] = freq.hash;
    hash_freq[hashes[0]]++;
    vector<int> prev_same(N + 1, 0);
    vector<int> last_seen(N + 1, 0);
    int64_t answer = 0;
    int start = 0;

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        prev_same[i] = last_seen[a];
        last_seen[a] = i;

        int remove = prev_same[prev_same[prev_same[i]]];

        while (start < remove) {
            hash_freq[hashes[start]]--;
            start++;
        }

        freq.modify(a, (freq[a] + 1) % 3);
        hashes[i] = freq.hash;
        answer += hash_freq[hashes[i]]++;
    }

    cout << answer << '\n';
}