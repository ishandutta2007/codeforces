#include <iostream>
using namespace std;

int main(){
    long long n, x, y;
    cin >> n >> x >> y;
    if(n > y){
        cout << -1 << endl;
        return 0;
    }
    long long t = y - n + 1;
    t *= t;
    if(t + n - 1 < x){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n - 1; i++)
        cout << "1 ";
    cout << y - n + 1 << endl;
    return 0;
}