/*
   .
#???????
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,a,b;
    cin >> n >> a >> b;
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        if(i-1>=a&&n-i<=b){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}