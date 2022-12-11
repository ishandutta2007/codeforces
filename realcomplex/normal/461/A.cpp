#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    ll sk[n+1];
    sk[0] = 0;
    for(int j = 1;j<=n;j++){
        cin >> sk[j];
    }
    sort(sk,sk+(n+1));
    for(int x = 1;x<=n;x++){
        sk[x] += sk[x-1];
    }
    ll sum = sk[n];
    for(int y = 1;y<n;y++){
        sum += sk[n]-sk[y];
        sum += sk[y]-sk[y-1];
    }
    cout << sum;
    return 0;
}