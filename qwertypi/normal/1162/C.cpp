#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <iomanip>
#define inf (1 << 30)
typedef long long ll;
using namespace std;

int pos[100001][2];
int main(){
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        pos[i][0] = inf;
        pos[i][1] = -inf;
    }
    for(int i=0;i<q;i++){
        int k;
        cin >> k;
        pos[k][0] = min(i, pos[k][0]);
        pos[k][1] = max(i, pos[k][1]);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j = max(1,i-1); j <= min(n,i+1); j++){
            ans += pos[i][0] > pos[j][1];
        }
    }
    cout << ans;
    return 0;
}