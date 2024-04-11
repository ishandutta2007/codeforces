#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int main(){

    string bad = "BCDEFGJKLNPQRSZ";
    string s;
    cin >> s;
    bool c1 = true;
    for(int i = 0;i<s.size();i++){
        if(bad.find(s[i]) != -1){
            c1 = false;
        }
    }
    if(c1 == false || s != string(s.rbegin(),s.rend())){
        cout << "NO";
    }
    else{
        cout << "YES";
    }
    return 0;
}