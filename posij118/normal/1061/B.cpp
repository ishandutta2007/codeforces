#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, cur, ne;
    cin >> n >> m;

    long long ans = 0;
    long long sum = 0;

    int a[n + 1];
    for(int i = 0; i<n; i++){
        cin >> a[i +1];
        sum += a[i + 1];
    }
    a[0] = 0;
    if(n == 1){
        cout << 0;
        return 0;
    }

    sort(a, a + n + 1);
    cur = a[n] + 1;

    for(int i = n; i >= 1; i--){
        ne = cur;
        cur = max(min(cur - 1, a[i - 1] + 1), 0);

        ans += max(1, (ne - cur));
    }

    cout << sum - ans;

}