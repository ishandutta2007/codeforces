#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main()
{
    int n;
    cin >> n;
    ll sk;
    for(int i = 0;i<n;i++){
        cin >> sk;
        if(sk&1){
            cout << "First";
            return 0;
        }
    }
    cout << "Second";
    return 0;
}