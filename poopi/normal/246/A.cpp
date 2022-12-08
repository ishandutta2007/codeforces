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
    if(n < 3)
        cout << -1 << endl;
    else{
        for(int i = n; i > 0; i--)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}