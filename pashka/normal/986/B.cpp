#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L
#define PI 3.141592653589793238462643383279502884L

#define long long long int

using std::vector;
using std::map;
using std::set;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::cerr;

// @author: pashka

vector<int> fenwick;

void init(int n) {
    fenwick.resize(n + 1);
}

long sum(int r) { // exclusive
    if (r == 0)
        return 0;
    r--;
    int result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        result += fenwick[r];
    return result;
}

void inc(int i, int d) {
    for (; i < fenwick.size(); i = (i | (i + 1)))
        fenwick[i] += d;
}

int sum(int l, int r) {
    return sum(r) - sum(l);
}

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;

    init(n + 1);

    int s = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += sum(x, n + 1);
        s &= 1;
        inc(x, 1);
    }


    if (s == (n & 1)) {
        cout << "Petr\n";
    } else {
        cout << "Um_nik\n";
    }

    return 0;
}