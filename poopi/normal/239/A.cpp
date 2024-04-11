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
    int y, k;
    cin >> y >> k >> n;
    if(y + - y % k + k > n){
        cout << -1 << endl;
        return 0;
    }
    for(int i = y + k - y % k; i <= n; i += k)
        cout << i - y << ' ';
    cout << endl;
    return 0;
}