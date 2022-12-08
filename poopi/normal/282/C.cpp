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

FILE* fin = fopen("input.txt", "r");
//FILE* fout = fopen("output.txt", "w");
ofstream fout ("output.txt");
//#define cout fout
//#define stdin fin
//#define stdout fout
#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define PLL pair<int64, int64>

int n, m;
int arr[100010];
vector <int> v[5010];

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int a = 0, b = 0;
    for(int i = 0; i < s1.length(); i++)
        if(s1[i] == '1') a = true;
    for(int i = 0; i < s2.length(); i++)
        if(s2[i] == '1') b = true;
    cout << (s1.length() != s2.length() || a != b ? "NO" : "YES") << endl;
    return 0;
}