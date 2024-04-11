#include <map>
#include <set>
#include <iostream>
#include <cstring>
#include <vector>
#include <cctype> 
#include <cstdio>
#include <string>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
//
struct p {
    long long z;
    long long t;
};
long long n, k;
vector <p> a;
bool cmp(p p1, p p2) {
    if (p1.z > p2.z) return 1;
    if (p1.z < p2.z) return 0;
    if (p1.t < p2.t) return 1;
    return 0;
}
//
int main() {
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        long long y, t;
        scanf("%d %d ", &y, &t);
        p nw;
        nw.z =  y;
        nw.t = t;
        a.push_back(nw);
    }
    sort(a.begin(), a.end(), cmp);
    long long z1 = a[k - 1].z;
    long long t1 = a[k - 1].t;
    long long sum = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i].z == z1 && a[i].t == t1)sum++;
    cout << sum << endl;
}