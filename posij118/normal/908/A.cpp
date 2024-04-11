#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int ans=0;
    char x[10]={'a', 'e', 'i', 'o', 'u', '1', '3', '5', '7', '9'};
    cin >> s;

    for(int i=0; i<s.size(); i++){
        for(int j=0; j<10; j++){
            if(s[i]==x[j]) ans++;
        }
    }

    cout << ans;

}