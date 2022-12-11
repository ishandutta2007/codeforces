#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main(){

    int n,m;
    cin >> n >> m;
    int ans = 0;
    for(int j = 0;j<=1000;j++){
        for(int x = 0;x<=1000;x++){
            if((j*j)+x == n && (x*x)+j == m){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}