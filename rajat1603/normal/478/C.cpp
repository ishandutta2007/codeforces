#include "bits/stdc++.h"
using namespace std;
long long a[3];
int main(){
    cin >> a[0] >> a[1] >> a[2];
    sort(a , a + 3);
    cout << min((a[0] + a[1] + a[2]) / 3 , a[0] + a[1]);
}