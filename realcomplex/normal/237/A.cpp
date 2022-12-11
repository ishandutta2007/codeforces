#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int t[24][60];

int main()
{
    int n;
    cin >> n;
    int a,b;
    int mx = 0;
    for(int i = 0;i<n;i++){
        cin >> a >> b;
        t[a][b]++;
        mx = max(t[a][b],mx);
    }
    cout << mx;
    return 0;
}