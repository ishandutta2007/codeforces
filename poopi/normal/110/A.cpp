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
    for(int i = 0; i < str.length(); i++)
        if(str[i] == '4' || str[i] == '7')
            cnt++;
    cout << (cnt == 7 || cnt == 4 ? "YES" : "NO") << endl;
    return 0;
}