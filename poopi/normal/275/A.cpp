                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>

int n, cnt;
int arr[210];
int mark[10][10];
int mn, mx;
string str[3] = {"chest", "biceps", "back"};
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int a;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> a;
            mark[i][j] += a;
            mark[i-1][j] += a;
            mark[i+1][j] += a;
            mark[i][j-1] += a;
            mark[i][j+1] += a;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cout << 1 - mark[i][j] % 2;
        cout << endl;
    }
    return 0;
}