#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e9
#define mp make_pair
#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,a,b;
    cin >> n >> a >> b;
    char s[n+1];
    for(int j = 1;j<=n;j++){
        cin >> s[j];
    }
    if(s[a] == s[b]){
        cout << 0;
        return 0;
    }
    cout << 1;
    return 0;
}