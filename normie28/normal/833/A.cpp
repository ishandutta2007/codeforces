
#include<bits/stdc++.h>
using namespace std;
 using LL = long long;
 map<LL, int> cube;
 
int main() {
    for(LL i = 1; i <= 1000000; i++) cube[i * i * i] = i;
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        LL a, b;
        cin >> a >> b;
        int qwq = cube.count(a * b) ? cube[a * b] : -1;
        if(qwq != -1 && a % qwq == 0 && b % qwq == 0) puts("Yes");
        else puts("No");
    }
    return 0;
}