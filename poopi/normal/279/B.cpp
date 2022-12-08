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
    int s = 0, t;
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        s += arr[i];
    }
    int p = 0, res = 0;
    s = 0;
    for(int i = 0; i < n; i++){
        while(p < n && s + arr[p] <= t)
            s += arr[p++];
        res = max(res, p - i);
        s -= arr[i];
    }
    cout << res << endl;
    return 0;
}