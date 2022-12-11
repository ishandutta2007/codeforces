#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9+7;
ll d[300005];
void ini(){
        d[0] = 1;
        for(int j = 1;j<300005;j++)d[j] = (d[j-1]*2)%mod;
}
int main(){
        ini();
        int n;
        cin >> n;
        int sk[n];
        for(int j = 0;j<n;j++)cin >> sk[j];
        sort(sk,sk+n);
        ll ans = 0;
        for(int j = 0;j<n;j++){
                ans = (ans-(sk[j]*(d[n-(j+1)]-d[j])))%mod;
        }
        cout << ans;
        return 0;
}