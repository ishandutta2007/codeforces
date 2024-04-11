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

int a[100010], b[100010];

int main(){ 
    cin >> n;
    int f = 2000000000, l = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        f = min(f, a[i]);
        l = max(l, b[i]);
    }
    int idx = -1;
    for(int i = 0; i < n; i++)
        if(a[i] == f && b[i] == l)
            idx = i + 1;
    cout << idx << endl;
    return 0;
}