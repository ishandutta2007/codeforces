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
const int INF = 1e18;

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    string mins=s, cur, pre;
    int mini = 1;
    loop(k,1,n+1){
        cur = "";
        pre = "";
        loop(i,k,n) cur+=s[i];
        loop(i,0,k) pre+=s[i];
        if ((n-k)%2){
            reverse(all(pre));
        }
        cur = cur + pre;
        if (mins>cur){
            mins = cur;
            mini = k + 1;
        }
    }
    cout<<mins<<endl;
    cout<<mini<<endl;
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
g++ b.cpp -o a & a
6
4
abab
6
qwerty
5
aaaaa
6
alaska
9
lfpbavjsm
1
p
*/