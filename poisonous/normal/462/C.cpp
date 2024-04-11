#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long int ll;

int n, seq[300005];
ll tot, ans;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &seq[i]);
        tot += seq[i];
    }
    ans = tot;
    sort(seq + 1, seq + 1 + n);
    for(int i = 1; i < n; ++ i){
        ans += tot;
        tot -= seq[i];
    }
    cout << ans << endl;
    return 0;
}