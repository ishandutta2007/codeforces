#include <bits/stdc++.h>
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
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;

const int LOG = 20;
int32_t main(){
    int n; cin>>n;
    string s,t; cin>>s>>t;
    set<int> o,z;
    loop(i,0,n){
        if (s[i]!=t[i]){
            if (s[i]=='0') z.insert(i);
            else o.insert(i);
        }
    }
    if (o.size()!=z.size()) return cout<<-1<<endl,0;
    int ans = 0;
    while(o.size() && z.size()){
        int ind = *o.begin(), ind2 = *z.begin();
        bool turn = 0, start = 0;
        int tmp;
        if (ind>ind2) ind  = ind2, turn = start = 1;
        while(1){
            if (turn){
                auto it = o.upper_bound(ind);
                if (it==o.end()) break;
                tmp = *it;
                if (start) o.erase(it), z.erase(ind);

            }
            else{
                auto it = z.upper_bound(ind);
                if (it==z.end()) break;
                tmp = *it;
                if (!start) z.erase(it), o.erase(ind);
            }
            ind = tmp;
            turn = !turn;
        }
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
10
1010111110
1011101101




. . . . . . . . . . . . . . 

*/