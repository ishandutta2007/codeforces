#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int n;
    cin >> n;
    int a;
    int res = 0;
    int mx=0;
    for(int i = 1; i <= n; i ++ ){
        cin >> a;
        mx = max(mx,a);
        if(i == mx){
            res ++ ;
        }
    }
    cout << res;
    return 0;
}