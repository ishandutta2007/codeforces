#include "bits/stdc++.h"
using namespace std;
int n;
string str = "1";
string inp;
int cnt0;
int tot = 0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> inp;
        if(inp == "0"){
            cout << 0;
            return 0;
        }
        cnt0 = 0;
        for(char c : inp){
            cnt0 += c - '0';
        }
        if(cnt0 > 1){
            str = inp;
        }
        else{
            tot += int(inp.size()) - 1;
        }
    }
    while(tot--){
        str += "0";
    }
    cout << str;
}