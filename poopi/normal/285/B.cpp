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
int arr[200010];
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int s, t;
    cin >> n >> s >> t;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    while(cnt < 2 * n && s != t){
        s = arr[s];
        cnt++;
    }
    if(cnt == 2 * n) cout << -1 << endl;
    else cout << cnt << endl;
    return 0;
}