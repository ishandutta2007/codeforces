#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#define inf (1 << 30)
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    int l_x = -inf;
    int l_h = inf;
    for(int i=0;i<n;i++){
        int x, h;
        cin >> x >> h;
        if(l_h != inf && x - l_x > l_h + h){
            ans += 2;
            l_h = inf;
        }else if(l_h != inf && x - l_x > l_h){
            ans++;
            l_h = h;
        }else if(x - l_x > h){
            ans++;
            l_h = inf;
        }else{
            l_h = h;
        }
        l_x = x;
    }
    if(l_h != inf){
        ans++;
    }
    cout << ans;
    return 0;
}