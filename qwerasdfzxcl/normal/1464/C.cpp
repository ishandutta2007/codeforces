#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n, t;
    string s;
    vector<ll> vec(26, 0);
    cin >> n >> t >> s;
    ll cur = 0;
    for (int i=0;i<n;i++){
        cur += 1LL<<(s[i]-'a');
    }
    cur -= 1LL<<(s[n-2]-'a'+1);
    if (cur-t<0 || (cur-t)&1){
        printf("No\n");
        return 0;
    }
    ll val = (cur-t)/2;
    //printf("%lld\n", val);
    for (int i=0;i<n-2;i++){
        vec[s[i]-'a']++;
    }
    for (int i=25;i>=0;i--){
        while(vec[i] && val>=(1LL<<i)){
            vec[i]--;
            val -= (1LL<<i);
            //printf("%lld\n", val);
        }
    }
    if (!val) printf("Yes\n");
    else printf("No\n");
    return 0;
}