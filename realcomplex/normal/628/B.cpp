#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e12

void open(){
    freopen("in.txt","r",stdin);
    //freopen("01.out","w",stdout);
}
main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    ll dp[n+1];
    dp[0] = 0;
    int p = 1;
    int l,r;
    for(int i = 0;i<n;i++){
        dp[p] = dp[p-1];
        if(s[i]%4==0) dp[p]++;
        if(i!=0){
            l = s[i-1]-48;
            r = s[i]-48;
            if(((l*10)+r)%4==0) dp[p]+=i;
        }
        p++;
    }
    cout << dp[n];
    return 0;
}