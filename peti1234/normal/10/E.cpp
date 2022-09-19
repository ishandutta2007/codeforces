#include<bits/stdc++.h>

using namespace std;

long long n, t[405], ans=2e9+5;

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }

    for (int i=2; i<=n; i++) {
        for (int j=i; j<=n; j++) {
            long long cnt=1, sum=t[j], ert=t[i-1]-1, ert2=0, cnt2=0;
            for (int k=i; k<=j; k++) {
                long long db=ert/t[k];
                cnt+=db;
                ert-=db*t[k];
                sum+=t[k]*db;
            }
            ert2=sum;
            for (int k=1; k<=n; k++) {
                long long db=ert2/t[k];
                cnt2+=db;
                ert2-=db*t[k];
            }

            if (cnt<cnt2) {
                ans=min(ans, sum);
            }
        }
    }
    cout << (ans>2*t[1] ? -1 : ans);
	return 0;
}