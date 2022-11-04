#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = (int) 100;

struct Data {
    int x, y;
}v[MAXN + 1];


inline int check(int a, int b, int i, int j) {
    int ans = v[i].x * v[i].y + v[j].x * v[j].y;
    if(v[i].x + v[j].x <= a && max(v[i].y, v[j].y) <= b)
        return ans;
    if(v[i].x + v[j].y <= a && max(v[i].y, v[j].x) <= b)
        return ans;
    if(v[i].y + v[j].x <= a && max(v[i].x, v[j].y) <= b)
        return ans;
    if(v[i].y + v[j].y <= a && max(v[i].x, v[j].x) <= b)
        return ans;
    return 0;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n, i, a, b, j;
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    for(i = 1; i <= n; i++)
        cin >> v[i].x >> v[i].y;
    int ans = 0;
    for(i = 1; i <= n; i++)
        for(j = i + 1; j <= n; j++) {
            ans = max(ans, check(a, b, i, j));
            ans = max(ans, check(b, a, i, j));
        }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}