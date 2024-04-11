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
P arr[100010];
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + n);
    if(n > 1 && arr[1].first == arr[0].first)
        cout << "Still Rozdil" << endl;
    else cout << arr[0].second + 1 << endl;
    return 0;
}