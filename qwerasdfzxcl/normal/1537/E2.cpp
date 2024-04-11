#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
string s, ans, ans2;
int p[500500];

void z_algo(string &s){
    int n = s.size();
    int r = -1, l = -1;
    fill(p, p+n, -1);
    for (int i=1;i<n;i++){
        if (i<=r) p[i] = min(r-i, p[i-l]);
        while(p[i]+i+1<n && s[p[i]+i+1]==s[p[i]+1]) p[i]++;
        if (r<i+p[i]) r = i+p[i], l = i;
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k >> s;
    ans2 = s;
    while((int)ans2.size()<k) ans2 += s;
    while((int)ans2.size()!=k) ans2.pop_back();
    z_algo(ans2);
    for (int i=1;i<k;i++) p[i]++;
    //for (int i=1;i<k;i++) printf("%d ", p[i]);
    for (int i=1;i<=n-1;i++){
        bool chk = 0;
        if (i+p[i]>=k || ans2[i+p[i]]>ans2[p[i]]) chk = 1;
        if (chk){
            string tmp;
            for (int j=0;j<i;j++) tmp.push_back(ans2[j]);
            while((int)ans.size()<k) ans += tmp;
            while((int)ans.size()!=k) ans.pop_back();
            cout << ans;
            return 0;
        }
    }
    cout << ans2;
    return 0;
}