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
    int a, b;
    int c1 = 0, c2 = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(a) c1++;
        if(b) c2++;
    }
    cout << min(c1, n - c1) + min(c2, n - c2) << endl;
    return 0;
}