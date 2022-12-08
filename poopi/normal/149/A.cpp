                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
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
set <char> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int a;
    cin >> n;
    for(int i = 0; i < 12; i++)
        cin >> arr[i];
    sort(arr, arr + 12);
    reverse(arr, arr + 12);
    int p = 0, sum = 0;
    while(p < 12 && sum < n)
        sum += arr[p++];
    if(sum < n) cout << -1 << endl;
    else cout << p << endl;
    return 0;
}