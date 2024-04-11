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

int n;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i++){
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
    }
    if(s1 < s2) cout << -1 << endl;
    if(s1 == s2) cout << 0 << endl;
    if(s1 > s2) cout << 1 << endl;
    return 0;
}