#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();

    bool a_first[n + 1];
    a_first[n] = 1;
    for(int i = n - 1; i>= 0; i--){
        if(s[i] == 'a' && a_first[i + 1] == 1) a_first[i] = 0;
        else if(s[i] == 'a' && a_first[i + 1] == 0) a_first[i] = 0;
        else a_first[i] = 1;
    }

    for(int i = 0; i<n; i++){
        if(a_first[i] != a_first[i + 1]) cout << 1 << " ";
        else cout << 0 << " ";
    }

}