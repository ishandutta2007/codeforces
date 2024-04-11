#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int _n[2] = {0,0},_m[2] = {0,0};
    for(int i=0;i<n;i++){
        int val;
        cin >> val;
        _n[val%2]++;
    }
    for(int i=0;i<m;i++){
        int val;
        cin >> val;
        _m[val%2]++;
    }
    cout << min(_n[0], _m[1])+min(_n[1], _m[0]);
    return 0;
}