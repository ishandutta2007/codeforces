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
P arr[210];
bool mark[210][4];
int mn, mx;
string str;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int m;
    cin >> n >> m;
    for(int i = 0; i * i <= n; i++)
        for(int j = 0; j * j <= m; j++)
            if(i * i + j == n && i + j * j == m)
                cnt++;
    cout << cnt << endl;
    return 0;
}