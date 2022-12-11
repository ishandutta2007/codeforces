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
    int mx,sk;
    mx = 0;
    for(int j = 0;j<n;j++){
        cin >> sk;
        mx = max(mx,sk);
    }
    if(mx<=25)cout << 0;
    else cout << mx-25;
    return 0;
}