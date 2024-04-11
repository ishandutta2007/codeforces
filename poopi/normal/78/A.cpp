                                        /* in the name of Allah */

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define PLL pair<int64, int64>

char ch[5] = {'a', 'o', 'i', 'u', 'e'};
int num[3] = {5, 7, 5};

bool isv(char c){
    for(int i = 0; i < 5; i++)
        if(ch[i] == c)
            return true;
    return false;
}

int main(){
    string str;
    for(int i = 0; i < 3; i++){
        getline(cin, str);
        int cnt = 0;
        for(int j = 0; j < str.length(); j++)
            if(isv(str[j]))
                cnt++;
        if(cnt != num[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}