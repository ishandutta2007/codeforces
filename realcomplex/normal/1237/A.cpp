#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n);
    vector<int> b(n);
    int bal = 0;
    for(int i = 0; i < n; i ++ ){
        cin >> a[i];
        b[i] = a[i]/2;
        bal += b[i];    
    }
    for(int i = 0 ; i < n; i ++ ){
        if(a[i] % 2 == 0){
            cout << b[i] << "\n";
            continue;
        }
        if(a[i] > 0){
            if(bal < 0){
                bal ++ ;
                b[i]++;
            }
        }
        else if(a[i] < 0){
            if(bal > 0){
                bal -- ;
                b[i] -- ;
            }
        }
        cout << b[i] << "\n";
    }
    return 0;
}