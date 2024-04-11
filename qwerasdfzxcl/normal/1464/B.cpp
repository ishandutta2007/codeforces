#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
string s, curs;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int x, y;
    cin >> s >> x >> y;
    curs = s;
    int n = s.size();
    int p = 0, q = 1;
    if (x<y) swap(p, q);
    for (int i=0;i<n;i++) if (s[i]=='?'){
        curs[i] = '0'+p;
    }
    ll ans=0, curval=0;
    ll b0=0, b1=0, c0=0, c1=0;
    for (int i=0;i<n;i++){
        if (curs[i]=='0') c0++;
        else c1++;
    }
    for (int i=0;i<n;i++){
        if (curs[i]=='0'){
            c0--;
            ans += c1*x+b1*y;
            b0++;
        }
        else{
            c1--;
            ans += c0*y+b0*x;
            b1++;
        }
    }
    ans /= 2;
    b0=0, b1=0, c0=0, c1=0;
    curval=ans;
    for (int i=0;i<n;i++){
        if (curs[i]=='0') c0++;
        else c1++;
    }
    for (int i=0;i<n;i++){
        if (s[i]!='?'){
            if (curs[i]=='0'){
                c0--;
                b0++;
            }
            else{
                c1--;
                b1++;
            }
            continue;
        }
        if (curs[i]=='0'){
            c0--;
            curval -= c1*x+b1*y;
            curval += c0*y+b0*x;
            b1++;
            ans = min(ans, curval);
        }
        else{
            c1--;
            curval += c1*x+b1*y;
            curval -= c0*y+b0*x;
            b0++;
            ans = min(ans, curval);
        }
    }
    printf("%lld\n", ans);
    return 0;
}