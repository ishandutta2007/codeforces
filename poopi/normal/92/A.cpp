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
    int m, p = 1;
    cin >> n >> m;
    while(m >= p){
        m -= p;
        p = p % n + 1;
    }
    cout << m << endl;
    return 0;
}