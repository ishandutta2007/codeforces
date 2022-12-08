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
int arr[210];
bool mark[210][4];
int mn, mx;
string str[3] = {"chest", "biceps", "back"};
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        arr[i % 3] += a;
    }
    for(int i = 0; i < 3; i++)
        if(arr[i] > arr[(i + 1) % 3] && arr[i] > arr[(i + 2) % 3])
            cout << str[i] << endl;
    return 0;
}