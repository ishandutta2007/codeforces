#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 5e3;

int v[MAXN + 1];

map <int, int> fr;

int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    int ans = 0;
    for(i = 1; i <= n; i++) {
        cin >> x;
        fr[x]++;
        if(fr[x] > ans)
            ans = fr[x];
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}