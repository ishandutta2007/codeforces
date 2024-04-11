                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define P pair<int, int>

string str;

bool can(int len){
    for(int i = 0; i + len <= str.length(); i++){
        for(int j = i + 1; j + len <= str.length(); j++){
            bool f = true;
            for(int k = 0; k < len; k++){
                if(str[i + k] != str[j + k])
                    f = false;
            }
            if(f) return true;
        }
    }
    return false;
}

int main(){
    cin >> str;
    for(int i = str.length() - 1; i > 0; i--){
        if(can(i)){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}