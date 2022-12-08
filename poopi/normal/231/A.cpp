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
    int cnt = 0;
    int a, b, c;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        if(a + b + c >= 2)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}