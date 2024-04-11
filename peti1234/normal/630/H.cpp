#include <bits/stdc++.h>

using namespace std;
long long n;
bool bm[8];
long long alatt(long long a, long long b) {
    long long ans=1;
    for (int i=1; i<=b; i++) bm[i]=0;
    for (int i=a; i>a-b; i--) {
        int i2=i;
        if (!bm[4] && i2%4==0) bm[4]=1, i2/=4;
        for (int j=b; j>=1; j--) {
            if (!bm[j] && i2%j==0) bm[j]=1, i2/=j;
        }
        ans*=i2;
    }
    return ans;
}
int main()
{
    cin >> n;
    cout << alatt(n, 5)*alatt(n, 5)*120 << "\n";
    return 0;
}