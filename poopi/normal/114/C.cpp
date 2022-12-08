

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

int gen[100010];
int tp[100010];

void calc(int idx, string s){
    int n = s.length();
    if(n >= 4 && s.substr(n - 4, 4) == "lios"){
        gen[idx] = 1;
        tp[idx] = 1;
    }
    else if(n >= 5 && s.substr(n - 5, 5) == "liala"){
        gen[idx] = 2;
        tp[idx] = 1;
    }
    else if(n >= 3 && s.substr(n - 3, 3) == "etr"){
        gen[idx] = 1;
        tp[idx] = 2;
    }
    else if(n >= 4 && s.substr(n - 4, 4) == "etra"){
        gen[idx] = 2;
        tp[idx] = 2;
    }
    else if(n >= 6 && s.substr(n - 6, 6) == "initis"){
        gen[idx] = 1;
        tp[idx] = 3;
    }
    else if(n >= 6 && s.substr(n - 6, 6) == "inites"){
        gen[idx] = 2;
        tp[idx] = 3;
    }
    else{
        gen[idx] = tp[idx] = -1;
    }
}

int main(){
    int n = 0;
    string s;
    while(cin >> s)
        calc(n++, s);
    if(n == 1)
        cout << (tp[0] != -1 ? "YES" : "NO") << endl;
    else{
        string res = "YES";
        int cnt = (tp[0] == 2 ? 1 : 0);
        for(int i = 1; i < n; i++){
            if(gen[i] == -1 || gen[i] != gen[i - 1] || tp[i] < tp[i - 1])
                res = "NO";
            if(tp[i] == 2)
                cnt++;
        }
        if(cnt != 1)
            res = "NO";
        cout << res << endl;
    }
    return 0;
}