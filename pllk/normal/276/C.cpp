#include <iostream>
#include <algorithm>

#define ll long long int

using namespace std;

int n, q;
int a[2*100000];
int q1[2*100000];
int q2[2*100000];
int t[2*100000];
ll s;

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(&a[0], &a[n]);
    for (int i = 0; i < q; i++) {
        cin >> q1[i] >> q2[i];
        q1[i]--;
    }
    sort(&q1[0], &q1[q]);
    sort(&q2[0], &q2[q]);
    int k1 = 0, k2 = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k1 < q && q1[k1] == i) {
            k1++;
            k++;
        }
        while (k2 < q && q2[k2] == i) {
            k2++;
            k--;
        }
        t[i] = k;
    }
    sort(&t[0], &t[n]);
    for (int i = 0; i < n; i++) s += (ll)t[i]*a[i];
    cout << s << endl;
}