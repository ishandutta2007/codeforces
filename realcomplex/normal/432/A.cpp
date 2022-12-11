#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second


int main()
{
    int n,k;
    cin >> n >> k;
    int t = 5-k;
    int sk;
    int am = 0;
    for(int i = 0 ;i<n;i++){
        cin >> sk;
        if(sk <= t){
            am++;
        }
    }
    cout << am / 3;
    return 0;
}