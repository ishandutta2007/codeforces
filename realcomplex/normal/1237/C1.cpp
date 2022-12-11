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

const int N = (int)1e5 + 10;
int x[N];
int y[N];
int z[N];
bool dead[N];

int get_dis(int i, int j){
    return abs(x[i]-x[j]) + abs(y[i]-y[j]) + abs(z[i]-z[j]);
}

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i ++ ){
        cin >> x[i] >> y[i] >> z[i];
    }
    int l;
    for(int i = 0 ; i < n; i ++ ){
        if(!dead[i]){
            dead[i]=true;
            l = -1;
            for(int t = 0; t < n; t ++ ){
                if(!dead[t]){
                    if(l == -1 || get_dis(i, t) < get_dis(i, l)){
                        l = t;
                    }
                }
            }
            dead[l]=true;
            cout << i + 1 << " " << l + 1 << "\n";
        }
    }
    return 0;
}