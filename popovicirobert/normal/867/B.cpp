#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = (int) 1e5;



int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int a;
    ios::sync_with_stdio(false);
    cin >> a;
    if(a == 1) {
        cout << 1 << " " << 1 << endl << 1;
        return 0;
    }
    int s = (int) (1e6 / (a - 1)) * (a - 1);
    cout << s << " " << 2 << endl;
    int x = 1;
    while(!(1LL * x * (a - 1) <= s && 1LL * x * a > s))
        x++;
    cout << 1 << " " << x;
    //cin.close();
    //cout.close();
    return 0;
}