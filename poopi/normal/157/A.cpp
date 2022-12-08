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
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int mat[50][50];
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int t1 = 0, t2 = 0;
            for(int k = 0; k < n; k++){
                t1 += mat[i][k];
                t2 += mat[k][j];
            }
            if(t2 > t1) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}