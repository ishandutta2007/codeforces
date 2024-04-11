#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <iomanip>
#include <vector>
#define inf (1 << 30)
typedef long long ll;
using namespace std;

int cnt[51];
int main(){
    int n, t;
    cin >> n >> t;
    int sc;
    int ans = 0;
    for(int i=0;i<t;i++){
        cin >> sc;
        if(sc > 0){
            ans++;
        }
    }
    for(int i=t;i<n;i++){
        int _sc;
        cin >> _sc;
        if(sc == _sc && _sc > 0){
            ans++;
        }
    }
    cout << ans;
    return 0;
}