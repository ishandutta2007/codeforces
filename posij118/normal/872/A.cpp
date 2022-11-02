#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, ma, mb;
    ma=10;
    mb=10;
    cin >> n >> m;

    int a[n], b[m];
    int cnt[10];
    fill (cnt, cnt + 10, 0);

    for(int i=0; i<n; i++){
        cin >> a[i];
        ma=min(ma, a[i]);
        cnt[a[i]]++;
    }

    for(int i=0; i<m; i++){
        cin >> b[i];
        mb=min(mb, b[i]);
        cnt[b[i]]++;
    }

    for(int i=1; i<10; i++){
        if(cnt[i]==2){
            cout << i;
            return 0;
        }
    }

    cout << 10*min(ma, mb)+max(ma, mb);

}