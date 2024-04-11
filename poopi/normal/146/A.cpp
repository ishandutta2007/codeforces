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
    int h = 0;
    bool f = true;
    string str;
    cin >> n >> str;
    for(int i = 0; i < n; i++){
        cnt += str[i] - '0';
        if(i < n / 2) h += str[i] - '0';
        if(str[i] != '4' && str[i] != '7')
            f = false;
    }
    cout << (f && h == cnt - h ? "YES" : "NO") << endl;
    return 0;
}