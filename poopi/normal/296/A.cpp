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
int arr[2 * Max];
int mat[110][110];
bool npr[Max];
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    cin >> n;
    int a, mx = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        arr[a]++;
        mx = max(mx, arr[a]);
    }
    cout << (mx <= (n + 1) / 2 ? "YES" : "NO") << endl;
    return 0;
}