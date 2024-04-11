#include "bits/stdc++.h"
using namespace std;
const int N = 1005;
string str;
bool vowel(char c){
    if(c == 'A' || c == 'E' || c == 'O' || c == 'U' || c == 'I' || c == 'Y'){
        return 1;
    }
    return 0;
}
int main(){
    cin >> str;
    str = "A" + str + "A";
    int ans = 0;
    int last = 0;
    for(int i = 1 ; i < str.size() ; ++i){
        if(vowel(str[i])){
            ans = max(ans , i - last);
            last = i;
        }
    }
    cout << ans;
}