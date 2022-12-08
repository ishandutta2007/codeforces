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
    string s, t;
    cin >> s >> t;
    int p = 0;
    for(int i = 0; i < t.length(); i++)
        if(t[i] == s[p]) p++;
    cout << p + 1 << endl;
    return 0;
}