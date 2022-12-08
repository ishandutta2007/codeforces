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
#define Max 1000010

int main(){
    string s1, s2;
    string t1, t2;
    cin >> s1 >> s2;
    if(s1.length() != s2.length()){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < s1.length(); i++)
        if(s1[i] != s2[i])
            t1 += s1[i], t2 += s2[i];
    if(t1.length() == 2 && t1[0] == t2[1] && t1[1] == t2[0])
        cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}