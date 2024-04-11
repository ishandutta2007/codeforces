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
    int a, b, c;
    a = b = c = 0;
    string str;
    cin >> n >> str;
    for(int i = 0; i < n; i++){
        if(str[i] == 'I') a++;
        if(str[i] == 'A') b++;
        if(str[i] == 'F') c++;
    }
    if(a == 0) cout << b << endl;
    else if(a == 1) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}