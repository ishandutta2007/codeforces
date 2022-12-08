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
    int s = 0, a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        s += a;
    }
    for(int i = 1; i <= 5; i++)
        if((s + i) % (n + 1) != 1)
            cnt++;
    cout << cnt << endl;
    return 0;
}