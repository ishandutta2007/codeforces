#include <iostream>
#define inf (1 << 14)
using namespace std;
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int _max = -inf;
    int _min = inf;
    for(int i=0;i<n;i++){
        int v;
        cin >> v;
        _min = min(v, _min);
    }
    for(int i=0;i<m;i++){
        int v;
        cin >> v;
        _max = max(v, _max);
    }
    if(_max <= _min){
        cout << k;
    }else{
        cout << k / _min * _max + k % _min;
    }
    return 0;
}