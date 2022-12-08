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
string str;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    cin >> str;
    int mx = 0;
    for(int i = 0; i < str.length(); i++){
        if(i == 0 || str[i] != str[i - 1])
            cnt = 1;
        else cnt++;
        mx = max(mx, cnt);
    }
    cout << (mx >= 7 ? "YES" : "NO") << endl;
    return 0;
}