#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("no-stack-protector")

using namespace std;
const int inf = 1e9 + 7;
const int max_n = 5001;
int n, d;
int min_sum, sum;
int Min[30], sz_min;
int h;
int res[max_n];
int first_alive;
int cnt_alive;


bool check(int v, int dep) {
    int new_min_sum = dep + 1 + min_sum - min(sz_min, dep + 1);
    int new_sum = sum + dep + 1;
    int new_h = max(h, dep + 2);
    int new_max_sum = new_sum + new_h * (cnt_alive - 1);
    if (cnt_alive > 1) new_max_sum += (cnt_alive - 2) * (cnt_alive - 1) / 2;

    if (d < new_min_sum || d > new_max_sum) return false;

    min_sum = new_min_sum;
    sum = new_sum;

    if (dep + 1 < sz_min) Min[dep + 1]--;
    else Min[sz_min]--;
    while (Min[sz_min] == 0) sz_min--;

    h = new_h;
    res[first_alive] = v;
    first_alive++;
    cnt_alive--;
    return true;
}


bool dfs(int v, int dep) {
    //cout << v << " " << dep << " " << min_sum << " " << sum << " " << cnt_alive << '\n';
    if (d < min_sum || d > sum + h * cnt_alive + (cnt_alive - 1) * cnt_alive / 2) return false;
    if(first_alive >= n) return true;

    if (!check(v, dep)) return false;
    dfs(first_alive - 1, dep + 1);

    if (first_alive >= n) return true;
    if (!check(v, dep)) return false;
    return dfs(first_alive - 1, dep + 1);
}



signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int test;
    cin >> test;
    while(test--) {
        cin >> n >> d;
        sum = 0;

        min_sum = 0;
        int temp1 = 2;
        int temp2 = 1;
        sz_min = 0;
        while(temp2 != n) {
            sz_min++;
            Min[sz_min] = min(temp1, n - temp2);
            temp2 += Min[sz_min];
            min_sum += Min[sz_min] * sz_min;
            temp1 *= 2;
        }



        h = 1;
        first_alive = 1;
        cnt_alive = n - 1;


        if (!dfs(0, 0)) cout << "NO" << '\n';
        else{
            cout << "YES" << '\n';
            for(int i = 1;i < n;i++) cout << res[i] + 1 << " ";
            cout << '\n';
        }
    }

}