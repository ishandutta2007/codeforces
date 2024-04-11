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
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int m, a, b;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--;
        if(a > 0)
            arr[a - 1] += b - 1;
        if(a < n - 1)
            arr[a + 1] += arr[a] - b;
        arr[a] = 0;
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << endl;
    return 0;
}