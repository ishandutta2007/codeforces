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
    int64 t;
    find_prime();
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t;
        int64 x = sqrt((double)t) + 1e-9;
        cout << (x * x != t || npr[x] ? "NO" : "YES") << endl;
    }
    return 0;
}