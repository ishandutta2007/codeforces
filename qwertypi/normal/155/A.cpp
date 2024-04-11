#include <iostream>
#include <string>
#include <string.h>

#define inf (1 << 30)
using namespace std;

int main(){
    int n;
    cin >> n;
    int _max = -inf;
    int _min = inf;
    int ans = -2;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        if(k > _max){
            _max = k;
            ans++;
        }
        if(k < _min){
            _min = k;
            ans++;
        }
    }
    cout << ans;
}