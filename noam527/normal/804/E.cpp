#include <iostream>
using namespace std;
void pr(int a, int b){
    cout << a << " " << b << '\n';
}
int main(){
    int n, lo, hi, md;
    ios::sync_with_stdio(0), cin >> n, lo = 1, hi = n, md = n / 2 + 1;
    if (n % 4 > 1){
        cout << "NO"; return 0;
    }
    cout << "YES" << '\n';
    while (lo < hi){
        for (int i = lo + 1, j = hi - 1; i < j; i++, j--)
            pr(lo, i), pr(j, hi), pr(i, hi), pr(lo, j);
        if (n & 1)
            pr(lo, md), pr(lo, hi), pr(md, hi);
        else
            pr(lo, hi);
        lo++, hi--;
    }
}