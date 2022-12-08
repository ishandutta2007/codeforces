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

int main(){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> mat[i][j];
    mat[0][0] = (mat[1][2] - mat[0][1] + mat[0][2] + mat[2][0]) / 2;
    int s = mat[0][0] + mat[0][1] + mat[0][2];
    mat[1][1] = s - mat[1][0] - mat[1][2];
    mat[2][2] = s - mat[2][0] - mat[2][1];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cout << mat[i][j] << ' ';
        cout << endl;
    }
    return 0;
}