#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18;

int solve(){
    string s; cin>>s;
    int n = s.size();
    loop(i,0,n) s[i]-='A';
    string t;
    loop(i,0,n){
        if (t.size() && !t.back() && s[i]){
            t.pop_back();
        }
        else t+=s[i];
    }
    s = ""; n = t.size();
    loop(i,0,n){
        if (s.size() && s.back() && t[i]){
            s.pop_back();
        }
        else s+=t[i];
    }
    cout<<s.size()<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
3
AAA
BABA
AABBBABBBB


*/