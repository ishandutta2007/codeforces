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
    int a[100], b[100], m;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> b[i];
    int mx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(b[j] % a[i] == 0){
                if(mx == b[j] / a[i])
                    cnt++;
                if(mx < b[j] / a[i]){
                    mx = b[j] / a[i];
                    cnt = 1;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}