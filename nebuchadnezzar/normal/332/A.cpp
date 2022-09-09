#include <cstdio>
#include <iostream>

using namespace std;

int n;
string s;


int main(){
    cin >> n;
    cin >> s;

    int ans = 0;
    for(int i = n; i < s.length(); i += n){
        if(s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3]){
            ++ans;
        }
    }

    cout << ans;

    return 0;
}