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

//FILE* fin = fopen("input.txt", "r");
//#define stdin fin

FILE* fout = fopen("output.txt", "w");
#define stdout fout

ifstream fin ("input.txt");
#define cin fin

//ofstream fout ("output.txt");
//#define cout fout

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define PLL pair<int64, int64>

int n, m;
int arr[100010];
vector <int> v[5010];

int main(){
    int a;
    cin >> n;
    n *= 2;
    for(int i = 0; i < n; i++){
        //fscanf(stdin, "%d", &a);
        cin >> a;
        v[a].push_back(i + 1);
    }
    for(int i = 1; i <= 5000; i++){
        if(v[i].size() % 2){
            fprintf(fout, "-1");
            //cout << -1 << endl;
            return 0;
        }
    }
    for(int i = 1; i <= 5000; i++)
        for(int j = 0; j < v[i].size(); j += 2)
            //cout << v[i][j] << ' ' << v[i][j + 1] << endl;
            fprintf(stdout, "%d %d\n", v[i][j], v[i][j + 1]);
    return 0;
}