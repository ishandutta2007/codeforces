#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
using namespace std;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
inline int getint() {
    int val = 0;
    char c;
    while ((c = getchar()) && !(c >= '0' && c <= '9'));
    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val;
}
const long long INF = 100000000000000;
const int Y = 200;
//const int m = 1010;
long long coli[2101];
long long toans[2001];
long long arr[200000];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    n = getint();
    m = getint();
    if(n>m){
        cout<<0;
        return 0;
    }
    for (int i = 0; i < n; ++i)arr[i] = getint();
    sort(arr, arr + n);
    long long k = 1;
    for (int i = 0; i < n; ++i) {
        int tmp = arr[i] % m;
        for (int j = 0; j < m; ++j) {
            long long tmp2 = (tmp-j+m) % m;
            if (coli[j]) {
                tmp2 = (tmp2 * coli[j]) % m;
                k *= (long long)tmp2;
                k %= m;
            }
        }
        ++coli[tmp%m];
    }
    cout << k;
    return 0;
}