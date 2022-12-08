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
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    cin >> n;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        arr[a]++;
    }
    for(int i = 1; i <= 100; i++)
        cnt += arr[i] / 2;
    cout << cnt / 2 << endl;
    return 0;
}