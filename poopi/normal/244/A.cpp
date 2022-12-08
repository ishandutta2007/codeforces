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
int arr[100010];
int mat[110][110];
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

bool mark[1000];
vector <int> v[50];

int main(){ 
    int k, a;
    cin >> n >> k;
    memset(arr, -1, sizeof arr);
    for(int i = 0; i < k; i++){
        cin >> a;
        mark[a - 1] = true;
        v[i].push_back(a);
    }
    int p = 0;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n - 1; j++){
            while(mark[p]) p++;
            mark[p] = true;
            v[i].push_back(p + 1);
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++)
            cout << v[i][j] << ' ';
        cout << endl;
    }
    return 0;
}