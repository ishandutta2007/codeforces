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
int arr[210];
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    cin >> n;
    for(int i = 0; i < 7; i++)
        cin >> arr[i + 1];
    int p = 0;
    while(n > 0){
        p = p % 7 + 1;
        n -= arr[p];
    }
    cout << p << endl;
    return 0;
}