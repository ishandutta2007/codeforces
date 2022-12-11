#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int l;
    cin >> l;
    int ans = l+1;
    int h;
    for(int j = 1;j<n;j++){
        cin >> h;
        ans += abs(l-h)+2;
        l = h;
    }
    cout << ans;
    return 0;
}