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
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    string str[110];
    int m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> str[i];
    for(int j = 0; j < m; j++)
        for(int i = 0; i < n; i++)
            arr[j] = max(arr[j], str[i][j] - '0');
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(str[i][j] - '0' == arr[j]){
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}