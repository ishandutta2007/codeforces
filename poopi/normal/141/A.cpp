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

int n, cnt[30];
set <char> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    string str;
    for(int i = 0; i < 3; i++){
        cin >> str;
        for(int j = 0; j < str.length(); j++)
            cnt[str[j] - 'A'] += (i == 2 ? 1 : -1);
    }
    str = "YES";
    for(int i = 0; i < 26; i++)
        if(cnt[i] != 0)
            str = "NO";
    cout << str << endl;
    return 0;
}