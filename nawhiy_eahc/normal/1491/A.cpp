#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, q; cin >> n >> q;
    int cnt1 = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i] == 1) cnt1++;
    }

    for(int i=1;i<=q;i++){
        int k; cin >> k;
        if(k == 1){
            int j; cin >> j;
            if(a[j] == 0) cnt1++;
            else cnt1--;
            a[j] = 1- a[j];
        }

        else{
            int j; cin >> j;
            if(cnt1 >= j) cout << "1\n";
            else cout << "0\n";
        }
    }
}