#include <bits/stdc++.h>
#define ll long long


using namespace std;



char v[] = {'v', '<', '^', '>'};

inline int check(int a, int b) {
    if(b - a < 0)
        return b - a + 4;
    return b - a;
}


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n;
    char ch1, ch2;
    ios::sync_with_stdio(false);
    cin >> ch1 >> ch2;
    cin >> n;
    int i = 0, j = 0;
    while(v[i] != ch1)
        i++;
    while(v[j] != ch2)
        j++;
    if((n - check(i, j)) % 4 == 0 && (n - check(j, i)) % 4 == 0) {
        cout << "undefined";
        return 0;
    }
    if((n - check(i, j)) % 4 == 0)
        cout << "cw";
    else
        cout << "ccw";
    //cin.close();
    //cout.close();
    return 0;
}