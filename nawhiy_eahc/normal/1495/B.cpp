#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int p[100002], l[100002], r[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for(int i=1;i<=n;i++)
        cin >> p[i];

    l[1] = 0; r[n] = 0;
    for(int i=2;i<=n;i++){
        if(p[i] > p[i-1]){
            l[i] = l[i-1] + 1;
        }
        else l[i] = 0;
    }
    for(int i=n-1;i>=1;i--){
        if(p[i] > p[i+1]){
            r[i] = r[i+1] + 1;
        }
        else r[i] = 0;
    }

    int M = 0, cnt = 0;
    for(int i=1;i<=n;i++){
        if(M == l[i]) cnt++;
        else if(M < l[i]){
            M = l[i]; cnt = 1;
        }
        if(M == r[i]) cnt++;
        else if(M < r[i]){
            M = r[i]; cnt = 1;
        }
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        if(l[i] == 0 || r[i] == 0) continue;
        if(cnt == 2 && l[i] == M && r[i] == M && l[i]%2 == 0) ans++;
    }

    cout << ans;
}