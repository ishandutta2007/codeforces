#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int n, k;
    cin >> n >> k;
    priority_queue<ll> cuts;
    vector<ll> aa(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> aa[i];
    }
    sort(aa.begin(), aa.end());
    reverse(aa.begin(), aa.end());
    for(int i = 0 ; i <= k ; i ++ )
        cuts.push(0ll);
    ll sum;
    ll sol = 0;
    for(auto x : aa){
        sum = cuts.top();
        cuts.pop();
        sol += sum;
        sum += x;
        cuts.push(sum);
    }
    cout << sol << "\n";
    return 0;
}