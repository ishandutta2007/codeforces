                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>

int n;
string str;
char ch[6] = {'a', 'o', 'y', 'e', 'u', 'i'};

int main(){
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'A' & str[i] <= 'Z')
            str[i] += 'a' - 'A';
        bool f = false;
        for(int j = 0; j < 6; j++)
            if(str[i] == ch[j])
                f = true;
        if(!f) cout << '.' << str[i];
    }
    cout << endl;
    return 0;
}