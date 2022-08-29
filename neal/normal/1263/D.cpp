#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

struct union_find {
    vector<int> parent;
    vector<int> size;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        components = n;

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        components--;
        return true;
    }
};


const int ALPHABET = 26;

int N;
vector<string> passwords;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    passwords.resize(N);
    union_find UF(ALPHABET);

    for (string &pass : passwords) {
        cin >> pass;

        for (int i = 0; i < (int) pass.size(); i++)
            for (int j = i + 1; j < (int) pass.size(); j++)
                UF.unite(pass[i] - 'a', pass[j] - 'a');
    }

    vector<bool> appears(ALPHABET, false);

    for (string &pass : passwords)
        for (char c : pass)
            appears[UF.find(c - 'a')] = true;

    cout << accumulate(appears.begin(), appears.end(), 0) << '\n';
}