#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;--i)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 1e9+7;
const double eps = 1e-9;

int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b,p/2);
    return v*v*(p%2?b:1);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int k; cin>>k;
    int l = 1;
    while(1){
        int v = pp(l,10);
        if (v>=k) break;
        l++;
    }
    string s;
    string code = "codeforces";
    int mult = 1, left = pp(l,10)/l;
    loop(i,0,10){
        if (mult * left * (l-1)>=k){
            loop(j,0,l-1) s+=code[i];
            mult*=(l-1);
        }
        else{
            loop(j,0,l) s+=code[i];
            mult*=l;
        }
        left/=l;
    }
    cout<<s<<endl;
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
3
*/