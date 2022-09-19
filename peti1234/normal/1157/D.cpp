#include <bits/stdc++.h>

using namespace std;
long long n, k, ans[100005], e=1;
int main()
{
    cin >> n >> k;
    if (2*n<k*(k+1) || n==8 && k==3 || n==4 && k==2) {
        cout << "NO\n";
        return 0;
    }
    long long dif=(n-k*(k+1)/2);
    cout << "YES\n";
    if (k==1) {
        cout << n << "\n";
        return 0;
    }
    long long rem=dif%k;
    for (int i=1; i<=k; i++) {
        int s=0;
        if (rem>1 && i==k-1) {
            s++;
        }
        if (rem>0 && i==k) {
            s+=max(e, rem-1);
        }
        cout << i+dif/k+s << " ";
    }
    cout << "\n";
    return 0;
}