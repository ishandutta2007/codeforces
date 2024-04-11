                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>

int n, cnt;
int arr[200];
int mn, mx;
string str;
set <char> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int a, b;
    cin >> n >> a >> b;
    cout << n - max(a, n - b - 1) << endl;
    return 0;
}