                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    cin >> n;
    int sum = 0;
    for(int i = 2; i < n; i++){
        int t = n;
        while(t){
            sum += t % i;
            t /= i;
        }
    }
    int d = gcd(sum, n - 2);
    cout << sum / d << '/' << (n - 2) / d << endl;
    return 0;
}