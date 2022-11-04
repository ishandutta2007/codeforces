#include <bits/stdc++.h>


using namespace std;

vector <long long> v;

int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i;
    long long l, r, x, y;
    ios::sync_with_stdio(false);
    cin >> x >> y >> l >> r;
    long long px = 1;
    while(px <= r) {
        long long py = 1;
        while(px + py <= r) {
            if(px + py >= l)
                v.push_back(px + py);
            if(r / y < py)
                break;
            py *= y;
        }
        if(r / x < px)
            break;
        px *= x;
    }
    sort(v.begin(), v.end());
    long long ans = r - l + 1;
    if(!v.empty())
        ans = v[0] - l;
    for(i = 1; i < v.size(); i++)
        ans = max(ans, v[i] - v[i - 1] - 1);
    if(!v.empty())
        ans = max(ans, r - v.back());
    cout << ans;
   // cin.close();
   // cout.close();
    return 0;
}