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
    cnt = n;
    for(int i = 1; i < n; i++)
        cnt += i * (n - i);
    cout << cnt << endl;
    return 0;
}