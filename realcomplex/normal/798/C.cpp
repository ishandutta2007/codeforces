#include <bits/stdc++.h>

using namespace std;

int main(){
        int n;
        cin >> n;
        int ans = 0;
        int cnt = 0;
        int g = 0;
        int sk;
        for(int j = 0;j<n;j++){
                cin >> sk;
                g = __gcd(g,sk);
                if(sk&1)cnt++;
                else ans +=(cnt/2)+(2*(cnt&1)) ,cnt = 0;
        }
        ans += (cnt/2)+2*(cnt&1);
        cout << "YES\n";
        if(g==1)cout << ans;
        else cout << 0;
        cout << endl;
        return 0;
}