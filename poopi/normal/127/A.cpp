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
    int k;
    cin >> n >> k;
    double x[200], y[200];
    double res = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        if(i != 0){
            double dx = x[i] - x[i - 1];
            double dy = y[i] - y[i - 1];
            res += sqrt(dx * dx + dy * dy);
        }
    }
    cout.precision(8);
    cout.setf(ios::fixed | ios::showpoint);
    cout << k * res / 50. << endl;
    return 0;
}