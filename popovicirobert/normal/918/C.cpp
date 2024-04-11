#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 92

using namespace std;

string str;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j;
    ios::sync_with_stdio(false);
    cin >> str;
    int n = str.size();
    str = " " + str;
    int ans = 0;
    for(i = 1; i <= n; i++) {
        int cnt1 = 0, cnt2 = 0;
        for(j = i; j <= n; j++) {
            char it = str[j];
            if(it == '(') {
                cnt1++;
            }
            else if(it == ')') {
                if(cnt1 > 0) {
                    cnt1--;
                }
                else if(cnt2 > 0) {
                    cnt2--;
                    cnt1++;
                }
                else
                    break;
            }
            else {
                if(cnt1 > 0) {
                    cnt1--;
                    cnt2++;
                }
                else
                    cnt1++;
            }
            if(cnt1 == 0 && (j - i + 1) % 2 == 0) {
                //printf("%d %d\n" ,i,j);
                ans++;
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}