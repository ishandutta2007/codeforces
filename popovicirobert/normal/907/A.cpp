#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))

using namespace std;



int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int v1, v2, v3, vm;
    ios::sync_with_stdio(false);
    cin >> v1 >> v2 >> v3 >> vm;
    int a = max(vm, v3);
    int b = max(a + 1, max(v2, 2 * vm + 1));
    int c = max(v1, b + 1);
    //printf("%d %d %d\n" ,a,b,c);
    if(2 * vm >= a && a <= 2 * v3 && b <= 2 * v2 && c <= 2 * v1) {
        cout << c << endl << b << endl << a;
    }
    else {
        cout << -1;
    }
    //cin.close();
    //cout.close();
    return 0;
}