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

int n, k;
int p[110], h[110];
int q[110], s[110];
int rev[110];

int bef(){
    int res = 10000;
    for(int i = 0; i < n; i++)
        h[i] = i;
    for(int I = 0; I <= 100 && res == 10000; I++){
        bool f = true;
        for(int i = 0; i < n; i++){
            p[i] = h[i];
            if(p[i] != s[i])
                f = false;
        }
        if(f) res = I;
        for(int i = 0; i < n; i++)
            h[i] = p[rev[i]];
    }
    return res;
}

int next(){
    int res = 10000;
    for(int i = 0; i < n; i++)
        h[i] = i;
    for(int I = 0; I <= 100 && res == 10000; I++){
        bool f = true;
        for(int i = 0; i < n; i++){
            p[i] = h[i];
            if(p[i] != s[i])
                f = false;
        }
        if(f) res = I;
        for(int i = 0; i < n; i++)
            h[i] = p[q[i]];
    }
    return res;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> q[i];
        q[i]--;
        rev[q[i]] = i;
    }
    for(int i = 0; i < n; i++){
        cin >> s[i];
        s[i]--;
    }
    int t1 = bef();
    int t2 = next();
    if(t1 == 0 && t2 == 0)
        cout << "NO" << endl;
    else if(t1 == 1 && t2 == 1)
        cout << (k == 1 ? "YES" : "NO") << endl;
    else if((t1 <= k && k % 2 == t1 % 2) || (t2 <= k && k % 2 == t2 % 2))
        cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}