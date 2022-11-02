#include <iostream>

using namespace std;

int main(){
    long long n;
    cin >> n;
    long long min = 1e9 + 1, max = 0;
    for (long long i = 0; i < n; ++i){
        long long a;
        cin >> a;
        if (a < min)
            min = a;
        if (a > max)
            max = a;
    }
    cout << max - min - n + 1;
}