#include <bits/stdc++.h>
 
using namespace std;
int n, k, maxi;
string s;
int main()
{
    cin >> n >> k >> s;
    int bal=0, jobb=-1, a=0, b=0;
    while (true) {
        if (a<=k || b<=k) {
            maxi=max(maxi, jobb-bal+1);
            jobb++;
            if (jobb==n) {
                break;
            }
            if (s[jobb]=='a') a++;
            else b++;
        } else {
            if (s[bal]=='a') a--;
            else b--;
            bal++;
        }
    }
    cout << maxi << "\n";
    return 0;
}