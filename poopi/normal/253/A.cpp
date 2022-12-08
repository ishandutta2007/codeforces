                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <set>
#include <fstream>
using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");
#define cin fin
#define cout fout
#define int64 long long
#define P pair<int, int>
#define Max 1000010

int n, cnt;
int arr[Max];
int mat[110][110];
bool npr[Max];
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int g, b;
    cin >> b >> g;
    if(g > b){
        cout << "G";
        g--;
    }
    while(g + b > 0){
        if(b > 0){
            cout << "B";
            b--;
        }
        if(g > 0){
            cout << "G";
            g--;
        }
    }
    cout << endl;
    cout.flush();
    return 0;
}