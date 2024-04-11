#include <bits/stdc++.h>

using namespace std;
typedef long double dl;
typedef long long ll;
ll a[200000];
vector<int> q[64];
ll sum = 0, answer = 0, m = 0;
int main()
{
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    ll n, k, x = 1, xt;
    cin >> n >> k >> xt;
    for (int i = 0; i < n; i++){
        ll c;
        cin >> a[i];
        c = a[i];
        sum = sum | c;
        int it = 0;
        while (c > 0){
            it++;
            if (c % 2 == 1 && q[it - 1].size() < 2)
                q[it - 1].push_back(i), m = max(m, ll(it));
            c /= 2;
        }
    }
    for (int i = 0; i < k; i++)
        x = x * xt;
    for (int i = 0; i < n; i++){
        ll ans = sum;
        for (int j = 0; j < m; j++)
            if (q[j].size() == 1 && q[j][0] == i)
                ans = ans ^ (1 << j);
        ans = ans | (a[i] * x);
        answer = max(ans, answer);
    }
    cout << answer;
}