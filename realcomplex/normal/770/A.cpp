#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main()
{
    int n,k;
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        cout << char((i%k)+97);
    }
    return 0;
}