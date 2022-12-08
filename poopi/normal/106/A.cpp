                                        /* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>

char ch[9] = {'6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

int getIdx(char in){
    for(int i = 0; i < 9; i++)
        if(ch[i] == in)
            return i;
    return -1;
}

int main(){
    char a;
    string s1, s2;
    while(cin >> a >> s1 >> s2){
        if(s1[1] == s2[1])
            cout << ((getIdx(s1[0]) > getIdx(s2[0])) ? "YES" : "NO") << endl;
        else if(s1[1] == a)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}