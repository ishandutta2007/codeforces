#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1000000000

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

signed main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int ans = (1<<(n+1))-2;
    int r = n-1;
    for(int j = 0;j<n;j++){
        if(s[j] == '4') ans -= (1<<r);
        r--;
    }
    cout << ans;
    return 0;
}