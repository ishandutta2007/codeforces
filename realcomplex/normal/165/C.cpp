#include <bits/stdc++.h>

using namespace std;

#define INF 1e18
#define mp make_pair
#define fi first
#define se second

typedef long long ll;

ll f(ll sk){
    return(sk*(sk+1))/2;
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);
    map<int,int>am;
    int k;
    cin >> k;
    string s;
    cin >> s;
    if(k == 0){
        ll ans = 0;
        ll e = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '0'){
                e++;
            }
            else{
                ans += f(e);
                e = 0;
            }
        }
        ans += f(e);
        cout << ans;
        return 0;
    }
    int sum = 0;
    ll ans = 0;
    am[0] = 1;
    for(int i = 0;i<s.size();i++){
        sum += s[i]-48;
        am[sum]++;
        if(sum >= k){
            ans += am[sum-k];
        }
    }
    cout << ans;
    return 0;
}