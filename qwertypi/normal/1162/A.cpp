#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <iomanip>
#define inf (1 << 30)
typedef long long ll;
using namespace std;

int main(){
    int n, h, q;
    cin >> n >> h >> q;
    int height[100];
    fill(height, height+n, h);
    for(int i=0;i<q;i++){
        int l, r, h_i;
        cin >> l >> r >> h_i;
        l--;
        for(int i=l;i<r;i++){
            height[i] = min(height[i], h_i);
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += height[i]*height[i];
    }
    cout << ans;
    return 0;
}