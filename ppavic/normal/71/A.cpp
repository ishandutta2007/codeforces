#include <iostream>

using namespace std;

int n;
string s;

int main(){
    cin >> n;
    for(; n ; n--){
        cin >> s;
        if(s.size() <= 10) cout << s << endl;
        else cout << s[0] << s.size() - 2 << s[s.size() - 1] << endl;
    }
    
}