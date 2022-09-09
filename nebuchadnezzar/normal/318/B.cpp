#include <cstdio>
#include <iostream>

using namespace std;

string s;
long long ans, numo;

int main(){
    cin >> s;
    if(s.length() < 10){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < s.length() - 4; ++i){
        if(s[i] == 'h' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'v' && s[i + 4] == 'y'){
            //cout << "h " << i << endl;
            ++numo;
        }
        if(s[i] == 'm' && s[i + 1] == 'e' && s[i + 2] == 't' && s[i + 3] == 'a' && s[i + 4] == 'l'){
            ans += numo;
            //cout << "m " << i << endl;
        }

    }
    cout << ans;
    return 0;
}