#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second

int main()
{
    int n,x;
    cin >> n >> x;
    int am = 0;
    int sint;
    for(int i = 1;i<=n;i++){
        if(x % i == 0){
            sint = x / i;
            if(sint <= n){
                am++;
            }
        }
    }
    cout << am;
    return 0;
}