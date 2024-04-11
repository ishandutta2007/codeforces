#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, q;
    string a;
    cin >> n >> q >> a;

    int cnt = 0;
    for (int i=0;i<n-2;i++){
        if (a[i]=='a' && a[i+1]=='b' && a[i+2]=='c') cnt++;
    }

    while(q--){
        int x;
        char y;
        cin >> x >> y;
        --x;

        int org = 0;
        for (int i=max(x-2, 0);i<min(n-2, x+1);i++){
            if (a[i]=='a' && a[i+1]=='b' && a[i+2]=='c') org++;
        }
        a[x] = y;
        int cnt2 = 0;
        for (int i=max(x-2, 0);i<min(n-2, x+1);i++){
            if (a[i]=='a' && a[i+1]=='b' && a[i+2]=='c') cnt2++;
        }

        cnt += cnt2 - org;
        printf("%d\n", cnt);
    }
    return 0;
}