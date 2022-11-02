#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

int get_or(int i, int j){
    cout << "or " << i << ' ' << j << endl;
    int v;
    cin >> v;
    return v;
}

int get_and(int i, int j){
    cout << "and " << i << ' ' << j << endl;
    int v;
    cin >> v;
    return v;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int val12 = get_or(1, 2) + get_and(1, 2), val23 = get_or(2, 3) + get_and(2, 3), val13 = get_or(1, 3) + get_and(1, 3);
    a[0] = (val12 + val13 - val23) / 2;
    a[1] = (val23 + val12 - val13) / 2;
    a[2] = (val23 + val13 - val12) / 2;
    for (int i = 3; i < n; i++){
        a[i] = get_or(1, i + 1) + get_and(1, i + 1) - a[0];
    }
    sort(a.begin(), a.end());
    cout << "finish " << a[k - 1] << endl;
    return 0;
}