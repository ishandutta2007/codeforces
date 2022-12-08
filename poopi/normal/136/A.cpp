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

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        arr[a - 1] = i + 1;
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}