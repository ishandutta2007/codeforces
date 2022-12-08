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

int n, m, p;
int64 st[100010];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> st[i];
    cin >> m;
    int w, h;
    for(int i = 0; i < m; i++){
        cin >> w >> h;
        w--;
        w = max(w, p);
        cout << st[w] << endl;
        while(p + 1 < n && st[w] + h >= st[p + 1])
            p++;
        st[p] = st[w] + h;
    }
    return 0;
}