                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

#define P pair<int, int>

string str;

int main(){
    getline(cin, str);
    int cnt = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '@'){
            cnt++;
            str[i] = ' ';
        }
    }
    if(cnt != 1){
        cout << "NO" << endl;
        return 0;
    }
    istringstream sin(str);
    string us, tmp;
    sin >> us >> tmp;
    if(us.length() < 1 || us.length() > 16){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < us.length(); i++){
        if(!isalpha(us[i]) && (us[i] < '0' || us[i] > '9') && us[i] != '_'){
            cout << "NO" << endl;
            return 0;
        }
    }
    cnt = 0;
    for(int i = 0; i < tmp.length(); i++){
        if(tmp[i] == '/'){
            cnt++;
            tmp[i] = ' ';
        }
    }
    if(cnt > 1){
        cout << "NO" << endl;
        return 0;
    }
    istringstream sin2(tmp);
    string hs, sr;
    sin2 >> hs;
    if(cnt == 1){
        sin2 >> sr;
        if(sr.length() < 1 || sr.length() > 16){
            cout << "NO" << endl;
            return 0;
        }
        for(int i = 0; i < sr.length(); i++){
            if(!isalpha(sr[i]) && (sr[i] < '0' || sr[i] > '9') && sr[i] != '_'){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if(hs.length() < 1 || hs.length() > 32){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < hs.length(); i++){
        if(hs[i] == '.'){
            if(i == 0 || i + 1 == hs.length() || hs[i + 1] == '.'){
                cout << "NO" << endl;
                return 0;
            }
            hs[i] = ' ';
        }
    }
    istringstream sin3(hs);
    while(sin3 >> tmp){
        if(tmp.length() < 1 || tmp.length() > 16){
            cout << "NO" << endl;
            return 0;
        }
        for(int i = 0; i < tmp.length(); i++){
            if(!isalpha(tmp[i]) && (tmp[i] < '0' || tmp[i] > '9') && tmp[i] != '_'){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}