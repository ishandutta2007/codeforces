#include <bits/stdc++.h>

using namespace std;

vector <int> n[2];

int popcount(int s, int e, int x){
    int c = 0;
    for(int i = s; i <= e; i++)
        c += n[x][i];
    return c;
}

int main(){
    int m;
    cin >> m;
    for(int ii = 0; ii < m; ii++){
        n[0].clear();
        n[1].clear();
        long long int l, r;
        cin >> l >> r;
        if(l == r){
            cout << l << endl;
            continue;
        }
        while(l > 0 || r > 0){
            n[0].push_back(l % 2);
            n[1].push_back(r % 2);
            l /= 2;
            r /= 2;
        }
        int k = n[0].size() - 1;
        long long int ans = 0;
        while(n[0][k] == n[1][k]){
            ans += (long long int)n[0][k] << k;
            k --;
        }
        if(popcount(0, k - 1, 1) == k)
            ans += (long long int)1 << k;
        while(k > 0)
            ans += (long long int)1 << (--k);
        cout << ans << endl;
    }
    return 0;
}