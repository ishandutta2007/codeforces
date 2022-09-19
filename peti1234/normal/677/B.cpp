#include <bits/stdc++.h>

using namespace std;
long long t[100001];
int main()
{
    long long n, h, k;
    cin >> n >> h >> k;
    for (int i=1; i<n+1; i++){
        cin >> t[i];
    }
    long long van=0;
    long long db=0;
    for (int i=1; i<n+1; i++){
        db+=van/k;
        van=van%k;
        if(van+t[i]>h){
            van=max(0ll, van-k);
            db++;
        }
        van+=t[i];
    }
    if (van%k!=0) db++;
    db+=van/k;
    cout << db << endl;

    return 0;
}