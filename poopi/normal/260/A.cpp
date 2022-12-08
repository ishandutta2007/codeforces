                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <set>
#include <fstream>
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

int main(){
    int a, b;
    cin >> a >> b >> n;
    int t = (b - (a * 10) % b) % b;
    if(t < 10){
        cout << a << t;
        for(int i = 0; i < n - 1; i++)
            cout << 0;
        cout << endl;
    }
    else cout << -1 << endl;
    return 0;
}