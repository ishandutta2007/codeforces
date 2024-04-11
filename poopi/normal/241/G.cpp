                                        /* in the name of Allah */
//Only Idea for tests!
#include <iostream>
#include <fstream>
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

ifstream fin ("problem5.in");
ofstream fout ("problem5.in");

//#define cin fin
//#define cout fout
#define int64 long long
#define P pair<int, int>

int n;
vector <double> r, s;
int x[600];
int p[600];


int main(){
    cout << 500 << endl;
    cout << "0 1000000" << endl;
    int B = 400000;
    for(int i = 1; i <= 498; i++){
        B += 500 - i;
        cout << B << ' ' << 500 - i << endl;
        B += 500 - i;
    }
    cout << "1000000 1000000" << endl;
    return 0;
}