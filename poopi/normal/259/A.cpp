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
    string res = "YES", s;
    for(int i = 0; i < 8; i++){
        cin >> s;
        for(int j = 0; j < s.length(); j++)
            if(s[j] == s[(j + 7) % 8])
                res = "NO";
    }
    cout << res << endl;
    return 0;
}