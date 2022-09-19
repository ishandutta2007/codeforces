#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long t[c], kom[c], n, db;
void ch(int a, int b) {
    if (a>b) swap(a, b);
    if (a+2<=b && (t[a]^t[b])==kom[b-1]-kom[a]) {
        db++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        kom[i]=kom[i-1]+t[i];
    }
    for (int i=1; i<=n; i++) {
        long long sum=0;
        for (int j=i+1; j<n && sum<2*t[i]; j++) {
            sum+=t[j];
            if (t[i]>=t[j+1]) ch(i, j+1);
        }
        sum=0;
        for (int j=i-1; j>=2 && sum<2*t[i]; j--) {
            sum+=t[j];
            if (t[i]>t[j-1]) ch(i, j-1);
        }
    }
    cout << db << "\n";
    return 0;
}