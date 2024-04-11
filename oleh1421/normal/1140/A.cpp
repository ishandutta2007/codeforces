#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000001];
int main() {
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int maxx=0;
    int cnt=0;
    for (int i=1;i<=n;i++){
        maxx=max(maxx,a[i]);
        if (i>=maxx){
            cnt++;
            maxx=0;
        }
    }
    cout<<cnt;
    return 0;
}