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
    cin >> str;
    for(int i = 0; i + 2 < str.length(); i++)
        if(str.substr(i, 3) == "WUB")
            str[i] = str[i + 1] = str[i + 2] = ' ';
    istringstream sin(str);
    string s;
    while(sin >> s)
        cout << s << ' ';
    cout << endl;
    return 0;
}