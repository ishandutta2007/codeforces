#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second

int main()
{
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int sk;
    for(int i = 0;i<m;i++){
        cin >> sk;
        cout << upper_bound(a,a+n,sk)-a << " ";
    }
    return 0;
}