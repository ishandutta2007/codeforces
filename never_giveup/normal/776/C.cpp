#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100;

vector<ll> value;

map<ll, int> q;

int n;

ll a[maxn], k;

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n >> k;
    if (k == 1)
        value.push_back(1);
    else
    if (k == -1)
        value.push_back(1), value.push_back(-1);
    else{
        ll now = 1;
        while (abs(now) <= 1e9 * n){
            value.push_back(now), now *= k;
        }
    }
    q[0] = 1;
    ll sum = 0, answer = 0;
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        sum += x;
        for (int j = 0; j < value.size(); j++)
            answer += q[sum - value[j]];
        q[sum]++;
    }
    cout << answer;
}