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
int arr[14] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    string res = "NO";
    cin >> n;
    for(int i = 0; i < 14; i++)
        if(n % arr[i] == 0)
            res = "YES";
    cout << res << endl;
    return 0;
}