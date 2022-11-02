#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <queue>
#include <cmath>
#include <climits>
#include <ctime>

using namespace std;

char s1[1000000];
char s2[1000000];
char s3[1000000];
char s4[1000000];

int main() {
    int h12, h13, h14, h23, h24, h34;
    cin >> h12 >> h13 >> h14 >> h23 >> h24 >> h34;
    int len = 0;
    memset(s1, 'a', sizeof(s1));
    memset(s2, 'a', sizeof(s2));
    memset(s3, 'a', sizeof(s3));
    memset(s4, 'a', sizeof(s4));
    len = h12;
    memset(s2, 'b', h12);
    int k = h12 + h13 - h23;
    if (k < 0 || k % 2) {cout << -1 << endl; return 0;}
    k /= 2;
    if (h12 < k || h13 < k) {cout << -1 << endl; return 0;}
    memset(s3, 'b', k);
    memset(s3+h12, 'b', h13-k);
    len += (h13-k);
    int k2 = h12 + h14 - h24;
    if (k2 < 0 || k2 % 2) {cout << -1 << endl; return 0;}
    k2 /= 2;
    if (h12 < k2 || h14 < k2) {cout << -1 << endl; return 0;}
    int k3 = h13 + h14 - h34;
    if (k3 < 0 || k3 % 2) {cout << -1 << endl; return 0;}
    k3 /= 2;
    //printf("k2=%d k3=%d\n",k2,k3);
    if (h13 < k3 || h14 < k3) {cout << -1 << endl; return 0;}
    int common = max(k2 - (h12-k), k3 - (h13-k));
    common = max(common, k2+k3-h14);
    common = max(common, 0);
    memset(s4, 'b', common);
    if (k2 < common || k3 < common || common > k) {cout << -1 << endl; return 0;}
    //printf("common=%d %d %d %d\n",common,k2-common,k3-common,common - k2 - k3 + h14);
    memset(s4+k, 'b', k2-common);
    memset(s4+h12, 'b', k3-common);
    memset(s4+len, 'b', common - k2 - k3 + h14);
    len += common - k2 -k3 + h14;

    int L = len;//h12 + h13 - k;
    s1[L] = 0;
    s2[L] = 0;
    s3[L] = 0;
    s4[L] = 0;
    cout << L << endl << s1 << endl << s2 << endl << s3 << endl << s4 << endl;
}