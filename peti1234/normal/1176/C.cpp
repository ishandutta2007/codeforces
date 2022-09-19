#include <bits/stdc++.h>

using namespace std;
int n, t[45], db[7];
int main()
{
    t[4]=1, t[8]=2, t[15]=3, t[16]=4, t[23]=5, t[42]=6;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        int s=t[x];
        if (s==1 || db[s]<db[s-1]) {
            db[s]++;
        }
    }
    cout << n-6*db[6] << "\n";
    return 0;
}