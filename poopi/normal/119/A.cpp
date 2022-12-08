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

int n;
string str[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int a, b;
    cin >> a >> b >> n;
    while(true){
        int d = gcd(a, n);
        if(n < d){
            cout << 1 << endl;
            break;
        }
        n -= d;
        d = gcd(b, n);
        if(n < d){
            cout << 0 << endl;
            break;
        }
        n -= d;
    }
    return 0;
}