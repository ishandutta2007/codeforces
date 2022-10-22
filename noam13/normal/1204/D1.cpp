#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD=1e9+7, MAXN=1e6;


int32_t main(){
    ios_base::sync_with_stdio(false);
    string s; cin>>s;
    int n=s.size();
    loop(i,0,n) s[i]-='0';
    vi ones;
    loop(i,0,n){
        if (s[i]) ones.pb(i);
        else{
            if (ones.size()) ones.pop_back();
        }
    }
    for(auto o:ones) s[o]=0;
    loop(i,0,n) cout<<int(s[i]);
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ KirkBinaryString.cpp -o a & a
0111001100111011101000




*/