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
int arr[Max];
int mat[110][110];
bool npr[Max];
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

void find_prime(){
    npr[1] = true;
    for(int i = 2; i < Max; i++)
        if(!npr[i])
            for(int j = i + i; j < Max; j += i)
                npr[j] = true;
}

int main(){
    arr[0] = arr[1] = 0;
    arr[2] = 1;
    n = 2;
    while(arr[n] < 1000000000){
        arr[n + 1] = arr[n] + arr[n - 1];
        n++;
    }
    int t;
    cin >> t;
    while(arr[n] != t)
        n--;
    cout << arr[n - 1] << ' ' << arr[n - 2] << ' ' << 0 << endl;
    return 0;
}