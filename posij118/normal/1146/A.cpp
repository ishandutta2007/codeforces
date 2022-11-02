
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;

    int cnt = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == 'a') cnt++;
    }

    int ans = 0;
    while(2*cnt <= s.size()){
        s.pop_back();

    }

    cout << s.size();

}