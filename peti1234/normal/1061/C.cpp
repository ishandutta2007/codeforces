#include <bits/stdc++.h>

using namespace std;
long long jo[1000001];
long long mod=1000000007;
int n;
long long sum;
int t[100001];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    jo[0]=1;
    for (int j=1; j<=n; j++) {
        int x=t[j];
        for (int i=sqrt(x); i>0; i--) {
            if (x%i==0) {
                int y=x/i;
                jo[y]+=jo[y-1];
                jo[y]%=mod;
                if (y!=i) {
                jo[i]+=jo[i-1];
                jo[i]%=mod;
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        sum+=jo[i];
        //cout << jo[i] << endl;
        sum%=mod;
    }
    cout << sum << endl;
    return 0;
}