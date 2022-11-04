#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 97

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, k;
    ios::sync_with_stdio(false);
    cin >> k;
    i = 1;
    while(k > 0) {
        int s = 0;
        int aux = i;
        while(aux > 0) {
            s += aux % 10;
            aux /= 10;
        }
        if(s == 10)
            k--;
        i++;
    }
    cout << i - 1;
    //cin.close();
    //cout.close();
    return 0;
}