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
    int a, b, c;
    cin >> a >> b >> c;
    cout << a * b + a * c + b * c - a - b - c + 1 << endl;
    return 0;
}