#include <bits/stdc++.h>
 
using namespace std;
 
bool in_vowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main(){
    string s, t;
    cin >> s >> t;
    if(s.size() != t.size()){
        cout << "No" << endl;
        return 0;
    }else{
        for(int i = 0; i < s.size(); i++){
            if(in_vowel(s[i]) ^ in_vowel(t[i])){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}