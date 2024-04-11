#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int n;
string ans;

int cnt(string &s){
    int ret=0;
    for (int i=0;i<n*2;i++) if (s[i]=='0') ret++;
    return ret;
}

void query(string &a, string &b, int val){
    vector<int> v, w;
    for (int i=0;i<n*2;i++) if (a[i]-'0'==val && (int)v.size()<n) v.push_back(i);
    for (int i=0;i<n*2;i++) if (b[i]-'0'==val && (int)w.size()<n) w.push_back(i);
    int pt1=0, pt2=0;
    for (int i=0;i<n;i++){
        for (;pt1<v[i];pt1++) ans.push_back(a[pt1]);
        for (;pt2<w[i];pt2++) ans.push_back(b[pt2]);
        ans.push_back(val+'0');
        pt1++, pt2++;
    }
    for (;pt1<n*2;pt1++) ans.push_back(a[pt1]);
    for (;pt2<n*2;pt2++) ans.push_back(b[pt2]);
}

void solve(){
    ans.clear();
    cin >> n;
    //ans.resize(n*3);
    string p, q, r;
    cin >> p >> q >> r;
    int c1=cnt(p), c2=cnt(q), c3=cnt(r);
    if (c1>=n && c2>=n) query(p, q, 0);
    else if (c1>=n && c3>=n) query(p, r, 0);
    else if (c2>=n && c3>=n) query(q, r, 0);
    else if (c1<n && c2<n) query(p, q, 1);
    else if (c1<n && c3<n) query(p, r, 1);
    else if (c2<n && c3<n) query(q, r, 1);
    else assert(0);
    cout << ans << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}