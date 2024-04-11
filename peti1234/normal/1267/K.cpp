#include <bits/stdc++.h>

using namespace std;
int db[22];
int q;
int main()
{
    cin >> q;
    for (int i=1; i<=q; i++) {
        for (int i=0; i<22; i++) {
            db[i]=0;
        }
        long long x;
        long long ans=1, rossz=1;
        cin >> x;
        int maxi=2;
        for (int i=2; x>0; i++) {
            int a=x%i;
            db[a]++;
            x/=i;
            maxi=i;
        }
        int ossz=db[0]+db[1];
        for (int i=2; ossz>0; i++) {
            ans*=ossz;
            ossz--;
            if (i!=maxi) {
                rossz*=ossz;
            }
            ossz+=db[i];
        }
        rossz*=db[0];
        for (int i=0; i<22; i++) {
            for (int j=2; j<=db[i]; j++) {
                ans/=j;
                rossz/=j;
            }
        }
        cout << ans-rossz-1 << "\n";
    }
    return 0;
}