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

const int N = 310;

int t[N];

void inc(int i, int d){
    for (; i < N; i = (i | (i + 1))){
        t[i] += d;
    }
}

int get(int r){
    int ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1){
        ans += t[r];
    }
    return ans;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        for (int i = 0; i < N; i++) t[i] = 0;
        int n, m;
        cin >> n >> m;
        vector<int> a(m), b;
        map<int,int> pos;
        for (int i = 0; i < m; i++){
            cin >> a[i];
        }
        b = a;
        sort(b.begin(), b.end());
        for (int i = 0; i < b.size(); i++){
            pos[b[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i < m; i++){
            ans += get(pos[a[i]]);
            inc(pos[a[i]], 1);
            pos[a[i]]--;
        }
        cout << ans << endl;
    }
    return 0;
}