#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct W {
    int t,x;
};
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<W> d;
    int count = 1;
    int c = 0;
    int ans = 0;
    for(int i = 1;i < n;i++) {
        if (s[i] != s[i - 1]) {
            W a;
            a.x = count;
            if (s[i - 1] == 'S') a.t = -1;
            else {
                a.t = 1;
                ans = max(ans,a.x);
                c++;
            }
            d.push_back(a);
            count = 1;
        }else{
            count++;}
    }
    W a;
    a.x = count;
    if (s[n - 1] == 'S') a.t = -1;
    else {
        a.t = 1;
        ans = max(ans,a.x);
        c++;
    }
    d.push_back(a);
    int ind = 0;
    if (c > 1) ans++;
    if (d[0].t == -1) ind = 1;
    for(int i = ind + 2;i < d.size();i+= 2) {
        if (d[i - 1].x == 1 && c > 2) {
            ans = max(ans,d[i - 2].x + d[i].x + 1);
        }
        if (d[i - 1].x == 1) {
            ans = max(ans,d[i - 2].x + d[i].x);
        }
        ind = i;
    }
    cout << ans;
}