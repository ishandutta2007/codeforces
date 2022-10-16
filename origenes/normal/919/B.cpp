#include<iostream>
using namespace std;

bool judge(int a) {
    int ans = 0;
    while(a) {
        ans += a % 10;
        a /= 10;
        if(ans > 10) return false;
    }
    return ans == 10;
}

int main() {
    int n;
    cin >> n;
    int tot = 0;
    for(int i = 0; tot < n; i++)
        if(judge(i) && ++tot == n) {
            cout << i << '\n';
            return 0;
        }
}