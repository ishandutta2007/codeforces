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

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    string str, res = "NO";
    cin >> str;
    for(int i = 0; i < str.length(); i++)
        if(str[i] == 'H' || str[i] == 'Q' || str[i] == '9')
            res = "YES";
    cout << res << endl;
    return 0;
}