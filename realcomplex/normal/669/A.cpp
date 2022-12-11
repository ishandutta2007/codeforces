#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int ans = (n/3)*2;
    if(n%3!=0){
        ans++;
    }
    cout << ans;
    return 0;
}