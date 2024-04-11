#include <bits/stdc++.h>

using namespace std;
long long w, kezd, db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> kezd >> db;
        long long ans=kezd, s=db/4*4;
        for (long long i=s+1; i<=db; i++) {
            if ((kezd%2==0) == (i%4==0 || i%4==1)) ans-=i;
            else ans+=i;
        }
        cout << ans << "\n";
    }
    return 0;
}