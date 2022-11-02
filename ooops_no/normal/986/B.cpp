#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long 

mt19937 rnd(51);

const int N = 1e6 + 10;
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += i - get(a[i]);
        inc(a[i], 1);
    }
    cout << (ans % 2 == n % 2 ? "Petr" : "Um_nik") << endl;
    return 0;
}