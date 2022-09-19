#include <bits/stdc++.h>

using namespace std;
long long t[10], n, p=1;
string s="codeforces";
int main()
{
    for (int i=0; i<10; i++) t[i]=1;
    cin >> n;
    for (int i=0; i<1000; i++) {
        if (p>=n) break;
        int k=i%10;
        p/=t[k], p*=t[k]+1, t[k]++;
    }
    for (int i=0; i<10; i++) for (int j=0; j<t[i]; j++) cout << s[i];
    cout << "\n";
    return 0;
}