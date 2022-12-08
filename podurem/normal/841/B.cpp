#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long ch = 0, nch = 0, sum = 0;
    for (int i = 0; i < n; i++){
        long long x;
        cin >> x;
        sum += x;
        if (x % 2 == 0) ch++;
        else nch++;
    }
    if (sum % 2 == 1) cout << "First";
    else if (nch == 0) cout << "Second";
    else cout << "First";
    return 0;
}