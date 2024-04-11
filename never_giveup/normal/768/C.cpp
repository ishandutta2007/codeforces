#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100, maxw = 1024;

int q[maxw + 100], p[maxw + 100];

int n, zap, x;

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n >> zap >> x;
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        q[val]++;
    }
    for (int iter = 0; iter < zap; iter++){
        int cnt = 0;
        for (int i = 0; i < maxw; i++){
            if (cnt % 2 == 0)
                p[i ^ x] += (q[i] + 1) / 2, p[i] += q[i] - (q[i] + 1) / 2;
            else
                p[i ^ x] += q[i] / 2, p[i] += q[i] - q[i] / 2;
            cnt += q[i];
        }
        for (int i = 0; i < maxw; i++)
            q[i] = p[i], p[i] = 0;
    }
    for (int i = maxw - 1; i >= 0; i--)
    if (q[i] > 0){
        cout << i << ' ';
        break;
    }
    for (int i = 0; i < maxw; i++)
    if (q[i] > 0){
        cout << i;
        return 0;
    }
}