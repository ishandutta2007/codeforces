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
int arr[200];
int mn, mx;
string str;
set <char> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int a, b, s = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        s += arr[i];
    }
    cin >> a >> b;
    a--, b--;
    if(a > b) swap(a, b);
    int v = 0;
    for(int i = a; i < b; i++)
        v += arr[i];
    cout << min(v, s - v) << endl;
    return 0;
}