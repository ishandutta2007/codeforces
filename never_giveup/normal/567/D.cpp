#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double dl;
set<int> s;
int n, k, a, m;
int mk(int x){
    return (x + 1) / (a + 1);
}
int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(false);
    cin >> n >> k >> a >> m;
    int ans = mk(n);
    s.insert(0);
    s.insert(n + 1);
    for (int i = 1; i <= m; i++){
        int x;
        cin >> x;
        set<int> :: iterator it = s.lower_bound(x);
        int r = *it;
        it--;
        int l = *it;
        ans += -mk(r - l - 1) + mk(x - l - 1) + mk(r - x - 1);
        s.insert(x);
        if (ans < k){
            cout << i;
            return 0;
        }
    }
    cout << -1;
}