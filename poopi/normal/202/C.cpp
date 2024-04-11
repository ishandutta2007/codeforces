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
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>
#define MAX 18
set <int> st[MAX];

void insert(int idx, int val){
    for(set <int>:: iterator it = st[idx - 2].begin(); it != st[idx - 2].end(); it++)
        st[idx].insert(val + (*it));
}

int main(){
    st[1].insert(0);
    st[1].insert(1);
    st[2].insert(0);
    for(int i = 3; i < MAX; i++){
        if(i % 2)
            for(int j = 2; j <= (i - 1) * 2; j += 2)
                insert(i, j);
        else for(int j = 4; j <= (i / 4 + i / 4 - 1) * 4; j += 4)
                insert(i, j);
    }
    int n, r = 0;
    cin >> n;
    while(st[r].find(n) == st[r].end())
        r++;
    if(n == 3)
        cout << 5 << endl;
    else cout << r << endl;
    return 0;
}