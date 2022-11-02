#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    bool is_vert, is_hor;
    is_vert = 0;
    is_hor = 0;

    for(int i = 0; i<s.size(); i++){
        if(s[i] == '0'){
            if(is_vert){
                cout << 3 << " " << 1 << endl;

            }

            else cout << 1 << " " << 1 << endl;
            is_vert ^= 1;
        }

        else{
            if(is_hor){
                cout << 4 << " " << 1 << endl;
            }

            else cout << 4 << " " << 3 << endl;
            is_hor ^= 1;
        }
    }

}