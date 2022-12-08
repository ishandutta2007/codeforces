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
P arr[210];
bool mark[210][4];
int mn, mx;
string str;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int k;
    cin >> n >> k;
    for(int i = k + 1; i >= 1; i--)
        cout << i << ' ';
    for(int i = k + 2; i <= n; i++)
        cout << i << ' ';
    cout << endl;
    return 0;
}