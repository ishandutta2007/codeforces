#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int result = max(a+b, c+d);
        cout << result << endl;
    }
}