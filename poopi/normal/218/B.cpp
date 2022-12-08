                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>
#define Max 1000010

int n, cnt;
int arr[2 * Max];
int mat[110][110];
bool npr[Max];
priority_queue <int> a, b;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int m, t;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> t;
        a.push(t);
        b.push(-t);
    }
    int r1 = 0, r2 = 0;
    for(int i = 0; i < n; i++){
        int t = a.top();
        a.pop();
        if(t > 1)
            a.push(t - 1);
        r1 += t;
        t = b.top();
        b.pop();
        if(t < -1)
            b.push(t + 1);
        r2 -= t;
    }
    cout << r1 << ' ' << r2 << endl;
    return 0;
}