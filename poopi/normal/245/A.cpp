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
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        mat[a - 1][0] += b;
        mat[a - 1][1] += c;
    }
    cout << (mat[0][0] >= mat[0][1] ? "LIVE" : "DEAD") << endl;
    cout << (mat[1][0] >= mat[1][1] ? "LIVE" : "DEAD") << endl;
    return 0;
}