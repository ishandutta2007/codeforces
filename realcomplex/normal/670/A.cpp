#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main(){

    int n;
    cin >> n;
    int ans = (n/7)*2;
    if((n%7)==6){
        ans++;
    }
    cout << ans;
    ans = (n/7)*2;
    if(n%7>=2){
        ans+=2;
    }
    else if(n%7>=1){
        ans++;
    }
    cout << " " << ans;
    return 0;
}