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
P arr[100010];
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    vector <int> v[3];
    cin >> n;
    int t;
    for(int i = 0; i < n; i++){
        cin >> t;
        if(t < 0) v[0].push_back(t);
        if(t > 0) v[1].push_back(t);
        if(t == 0) v[2].push_back(t);
    }
    if(v[1].empty()){
        for(int i = 0; i < 2; i++){
            v[1].push_back(v[0].back());
            v[0].pop_back();
        }
    }
    if(v[0].size() % 2 == 0){
        v[2].push_back(v[0].back());
            v[0].pop_back();
    }
    for(int i = 0; i < 3; i++){
        cout << v[i].size();
        for(int j = 0; j < v[i].size(); j++)
            cout << ' ' << v[i][j];
        cout << endl;
    }
    return 0;
}