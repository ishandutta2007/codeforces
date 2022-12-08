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
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

bool mc[20], mr[20];

int main(){
    int r, c;
    cin >> r >> c;
    char ch;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> ch;
            if(ch == 'S')
                mr[i] = mc[j] = true;
        }
    }
    int cnt = r * c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            if(mr[i] && mc[j])
                cnt--;
    }
    cout << cnt << endl;
    return 0;
}