#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
string s, ans, ans2;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k >> s;
    ans2 = s;
    while((int)ans2.size()<k) ans2 += s;
    for (int i=0;i<n-1;i++){
        bool chk = 0;
        for (int j=0;j<k;j++){
            if (s[j%(i+1)]==ans2[j]) continue;
            if (s[j%(i+1)]<ans2[j]) chk = 1;
            break;
        }
        if (chk){
            string tmp;
            for (int j=0;j<=i;j++) tmp.push_back(s[j]);
            while((int)ans.size()<k) ans += tmp;
            while((int)ans.size()!=k) ans.pop_back();
            cout << ans;
            return 0;
        }
    }
    while((int)ans2.size()!=k) ans2.pop_back();
    cout << ans2;
    return 0;
}