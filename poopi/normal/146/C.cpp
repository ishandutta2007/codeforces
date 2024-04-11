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

char s1[100010], s2[100010];
int len;

int main(){
    scanf("%s%s", s1, s2);
    int a = 0, b = 0, c = 0, d = 0;
    len = strlen(s1);
    for(int i = 0; i < len; i++){
        if(s1[i] != s2[i]){
            if(s1[i] == '4')
                a++, d++;
            else b++, c++;
        }
    }
    cout << max(a, b) << endl;
    return 0;
}