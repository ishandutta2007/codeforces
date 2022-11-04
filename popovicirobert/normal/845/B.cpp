#include <bits/stdc++.h>
#define ll long long


using namespace std;


int v[10], vec[10];
int ans = 100;

void bkt(int lvl) {
    if(lvl == 6) {
        int cnt = 0;
        int s = 0;
        for(int i = 0; i < 6; i++) {
            if(i < 3)
               s += vec[i];
            else
               s -= vec[i];
            cnt += (v[i] != vec[i]);
        }
        if(s == 0)
            ans = min(ans, cnt);
    }
    else {
        for(int i = 0; i <= 9; i++) {
            vec[lvl] = i;
            bkt(lvl + 1);
        }
    }
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 0; i < 6; i++) {
        v[i] = n % 10;
        n /= 10;
    }
    bkt(0);
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}