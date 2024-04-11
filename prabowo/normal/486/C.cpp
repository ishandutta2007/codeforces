#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,p;
    char s[100005];
    cin >> n >> p;
    p--;
    if (p >= n/2) p = n-p-1;
    cin >> s;
    int ans = 0;
    int l=p, r=p;
    bool first = true;
    for (int i=0; i<n/2; i++){
        int tmp = abs(s[i] - s[n-i-1]);
        if (tmp > 13) tmp = 26 - tmp;
        if (tmp > 0){
            if (first){
                l = i; first = false;
            }
            r = i;
        }
        ans += tmp;
    }
    if (l > p) l = p;
    if (r < p) r = p;
    int t = min(r+p-2*l, 2*r-p-l);
    ans += t;
    cout << ans << endl;


    return 0;
}