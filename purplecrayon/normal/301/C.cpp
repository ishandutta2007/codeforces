#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 10; i++) cout << "??" << i << ">>" << i << "??\n";
    cout << "??>>?\n";
    for (int i = 0; i < 9; i++) cout << i << "?<>" << i+1 << '\n';
    cout << "9?>>?0\n?<>1\n>>??";
}