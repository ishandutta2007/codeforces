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
int arr[100010];
int mat[110][110];
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    for(int i = a; i <= x; i++)
        cnt += max(0, min(y, i - 1) - b + 1);
    cout << cnt << endl;
    for(int i = a; i <= x; i++)
        for(int j = b; j <= min(y, i - 1); j++)
            cout << i << ' ' << j << endl;
    return 0;
}