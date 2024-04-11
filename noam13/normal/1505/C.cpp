#include <bits/stdc++.h>
using namespace std;
#define int int64_t
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);(i)++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);(i)--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
const int INF = 1e9, MOD = 1e9+7;


int32_t main(){
    ios_base::sync_with_stdio(false);
    string s; cin>>s;
    for(auto& c:s) c-='A';
    if (s.size()==1) return cout<<"YES"<<endl,0;
    int a = s[0], b = s[1];
    loop(i,2,s.size()){
        int c = s[i];
        if ((a+b)%26 != c) return cout<<"NO"<<endl,0;
        a = b, b = c;
    }
    cout << "YES" <<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -D_GLIBCXX_DEBUG -o a & a
HELP


*/