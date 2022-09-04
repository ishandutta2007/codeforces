#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100;



int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    int t = 4 * 60;
    int n, k;
    cin >> n >> k;
    t -= k;
    for (int i = 0; i < n; i++){
        if (t < 5 * (i + 1)){
            cout << i;
            return 0;
        }
        t -= 5 * (i + 1);
    }
    cout << n;
}