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
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
const long long INF = 100000000000000;
const int Y = 200000;
const int m = 2;
bool visited[Y + 1];
long long arr[Y + 1];
long long Ref[Y + 1];
map<int, int>hv;
map<int, bool>vs;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    long long s = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        Ref[i] += arr[i];
        int tmp = arr[i] - i;
        if (vs[tmp]) {
            int ind = hv[tmp];
            Ref[i] += Ref[ind];
            hv[tmp] = i;
        }
        else {
            vs[tmp] = true;
            hv[tmp] = i;
        }
        s = max(s, Ref[i]);
    }
    cout << s;
    return 0;
}
//      6 2 5 9 1 2 1 1 3 10 1 6 1 4 6 1 6 5 1 2 6 2 3 6 1 5 3 1 4 5 1