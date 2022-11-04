#include <bits/stdc++.h>
#define lsb(x)
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;

int v[MAXN + 1];

ll ssm[MAXN + 1], sp[MAXN + 1];

int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, d;
    ios::sync_with_stdio(false);
    cin >> n >> d;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        sp[i] = sp[i - 1] + v[i];
        ssm[i] = sp[i];
    }
    ssm[n + 1] = -(1LL << 62);
    for(i = n; i >= 1; i--) {
        ssm[i] = max(ssm[i + 1], ssm[i]);
    }
    ll sum = 0;
    i = 1;
    while(i <= n && v[i] != 0) {
        sum += v[i];
        if(sum > d) {
            cout << -1;
            return 0;
        }
        i++;
    }
    int ans = 0;
    while(i <= n) {
        if(v[i] == 0) {
            if(sum < 0) {
                sum += max(0LL, (d - (ssm[i] - sp[i - 1])) - sum);
                if(sum < 0) {
                    cout << -1;
                    return 0;
                }
                ans++;
            }
        }
        else {
            sum += v[i];
            if(sum > d) {
                cout << -1;
                return 0;
            }
        }
        i++;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}