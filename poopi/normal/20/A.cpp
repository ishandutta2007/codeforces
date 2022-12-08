                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define P pair<int, int>

int n, t;
P arr[1010];

int main(){
    string str, res = "";
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(i > 0 && str[i] == '/' && str[i-1] == '/')
            continue;
        res += str[i];
    }
    while(res.length() > 1 && res[res.length() - 1] == '/')
        res = res.substr(0, res.length() - 1);
    cout << res << endl;
    return 0;
}