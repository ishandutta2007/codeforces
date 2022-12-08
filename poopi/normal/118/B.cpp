                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>

int n, cnt;
set <char> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    cin >> n;
    for(int i = 0; i < 2 * n + 1; i++){
        for(int j = 0; j < abs(i - n); j++)
            cout << "  ";
        int d = min(i, 2 * n - i);
        for(int j = 0; j < 2 * d + 1; j++){
            cout << d - abs(j - d);
            if(j == 2 * d) cout << endl;
            else cout << ' ';
        }
    }
    return 0;
}