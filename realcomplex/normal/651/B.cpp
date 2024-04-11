#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 10000000
#define mp make_pair
#define fi first
#define se second
int cnt[1005];
int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int mx =0 ;
    int x;
    for(int j = 0;j<n;j++){
        cin >> x;
        cnt[x]++;
        mx = max(mx,cnt[x]);
    }
    cout << n-mx;
    return 0;
}