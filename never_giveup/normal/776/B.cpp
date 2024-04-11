#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100;

int n;

int ans[maxn];

int mx[maxn];

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n;
    n++;
    int answer = 0;
    for (int i = 2; i <= n; i++){
        vector<int> a;
        int x = i;
        for (int j = 2; j <= sqrt(x); j++)
        if (x % j == 0){
            while (x % j == 0)
                x /= j;
            a.push_back(ans[j]);
        }
        for (int j = 0; j < a.size(); j++)
            mx[a[j]] = 1;
        int it = 1;
        while (mx[it] == 1)
            it++;
        ans[i] = it;
        for (int j = 0; j < a.size(); j++)
            mx[a[j]] = 0;
    }
    for (int i = 2; i <= n; i++)
        answer = max(answer, ans[i]);
    cout << answer << '\n';
    for (int i = 2; i <= n; i++)
    cout << ans[i] << ' ';
}