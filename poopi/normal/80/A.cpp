                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>

int n, cnt;
int arr[210];
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    vector <int> v;
    for(int i = 2; i < 60; i++){
        bool f = true;
        for(int j = 2; j < i; j++)
            if(i % j == 0)
                f = false;
        if(f) v.push_back(i);
    }
    int m;
    cin >> n >> m;
    for(int i = 0; i + 1 < v.size(); i++){
        if(v[i] == n && v[i + 1] == m){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}