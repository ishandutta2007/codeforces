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
    int a, b, mx = 0, cur = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        cur += b - a;
        mx = max(mx, cur);
    }
    cout << mx << endl;
    return 0;
}