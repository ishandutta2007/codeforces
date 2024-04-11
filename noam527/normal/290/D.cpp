#include <iostream>
#include <string>
using namespace std;

int main(){
    int n; string s;
    cin >> s >> n;
    for (int i = 0; i < s.size(); i++){
        s[i] %= 32;
        if (s[i] <= n) cout << char(s[i] + 64);
        else cout << char(s[i] + 96);
    }
}