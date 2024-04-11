#include <iostream>
#include <string>

using namespace std;

bool glasn(char c){
    if (c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u' || c == 'n')
        return true;
    return false;
}

int main(){
    string s;
    cin >> s;
    bool ans = true;
    for (int i = 0; i < (int)s.size() - 1; ++i){
        bool glasn1 = glasn(s[i]), glasn2 = glasn(s[i + 1]);
        if ((!glasn1 && !glasn2) || (s[i] != 'n' && s[i + 1] == 'n' && !glasn1)){
            ans = false;
        }
    }
    bool glasn1 = glasn(s[s.size() - 1]);
    if (!glasn1)
        ans = false;
    if (ans)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}