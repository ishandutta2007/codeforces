#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
// SUKA YA NE SDAMSYA BITVA ZA SNG ZA DEDOV SUKA
 
using namespace std;
typedef long long ll;
const int N = 2 * 1e5;
int n; ll s;
int l[N];
int r[N];
int ind[N];
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}
bool comp(int i, int j) {
    return l[i] > l[j];
}
 
 
void solve() {
    read(n);
    read(s);
    for (int i = 0; i < n; i++) {
        ind[i] = i;
        read(l[i]);
        read(r[i]);
    }
    if (n == 1) {
        if (s > r[0]) {
            print(r[0], '\n');
        } else {
            print(s, '\n');
        }
        return;
    }// rabotai
    sort(ind, ind + n, comp);
    int lg = 1; int rg = 1e9 + 1;
    while (rg - lg > 1) {
        int mg = (rg + lg) >> 1;
        ll money = s;
        int need = (n + 1) >> 1;
        for (int i = 0; i < n; i++) {
            int li = l[ind[i]];
            int ri = r[ind[i]];
            if (need > 0 and ri >= mg) {
                money -= max(mg, li);
                need -= 1;
            } else {
                money -= li;
            }
        }
        if (need == 0 and money >= 0) {
            lg = mg;
        } else {
            rg = mg;
        }
    }
    print(lg, '\n');
}
 
int main() {
	int t;
	read(t);
	while(t--) {
        solve();
	}
	return 0;
}