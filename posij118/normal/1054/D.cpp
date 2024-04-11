#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k, ans, cnt;

    cin >> n >> k;
    ans = (n*(n + 1)) / 2;

    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    int inv = (1 << k) - 1;
    map<int, int> xors;
    xors[0]++;
    int xo = 0;
    vector<int> used;
    used.push_back(0);

    for(int i = 0; i<n; i++){
        xo = xo ^ a[i];
        xors[xo]++;
        used.push_back(xo);
    }

    sort(used.begin(), used.end());
    vector<int> used2;
    used2.push_back(used[0]);
    for(int i = 1; i<used.size(); i++){
        if(used[i] != used[i - 1]) used2.push_back(used[i]);
    }

    map<int, int> vis;

    for(int i = 0; i<used2.size(); i++){
            if(vis[used2[i]] == 0){
                cnt = xors[used2[i]] + xors[used2[i] ^ inv];
                vis[used2[i]] = 1;
                vis[used2[i] ^ inv] = 1;

                ans -= (((cnt/2) * ((cnt/2) - 1)) + ((cnt + 1) / 2) * (((cnt + 1)/ 2) - 1)) / 2;
            }
    }

    cout << ans;

}