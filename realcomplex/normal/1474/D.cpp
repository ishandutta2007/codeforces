#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const ll inf = (ll)1e18;
ll A[N];
ll S[N];
ll pf[N];
ll suf[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        S[i]=A[i]-S[i-1];
        pf[i]=min(pf[i-1],S[i]);
    }
    for(int i = 1; i <= n + 2; i ++ ){
        suf[i]=inf;
    }
    for(int i = n; i >= 1; i -- ){
        suf[i]=min(suf[i+2],S[i]);
    }
    if(pf[n] >= 0 && S[n] == 0){
        cout << "YES\n";
        return;
    }
    for(int i = 1; i < n; i ++ ){
        if(pf[i - 1] >= 0){
            if(suf[i + 2] + 2ll * (A[i + 1] - A[i]) >= 0 && suf[i + 3] + 2ll*(A[i] - A[i + 1]) >= 0){
                if(A[i+1]-S[i-1] >= 0 && A[i]-(A[i+1]-S[i-1]) >= 0){
                    ll q[2];
                    q[i%2]=A[i];
                    q[(i+1)%2]=A[i+1];
                    if(2ll*(q[(n+1)%2]-q[n%2])+S[n]==0){
                        cout << "YES\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "NO\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}