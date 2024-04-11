//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=5000010;
const ll inf=1e18;
const ll mod=998244353;
int cnt=0;
vector<string> ask(vector<int>u){
    cnt++;
    cout<<"next ";
    for (int i:u) cout<<i<<" ";
    cout<<endl;
    int k;cin>>k;
    vector<string>v;
    for (int i=0;i<k;i++){
        string s;cin>>s;
        v.push_back(s);
    }
    return v;
}
void solve(int Case){
    for (int x=1;;x++){
        auto cur=ask({0});
        cur=ask({0,1,2,3,4,5,6,7,8});
        if (cur.size()==2){
            while (true){
                cur=ask({0,1,2,3,4,5,6,7,8,9});
                if (cur.size()==1){
                    cout<<"done"<<endl;
                    return;
                }
            }
        }
    }





}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**
1111111100000
11010110

problem B with higher constrains


3
1 R
5 R
10 R
100 G
3 G
7 G


1
4
2 3 1 4

8 1
1 3 5 2 4 7 6 8
1 8


1
5 2
-1 1 2 0 0


4 11

3 6
2 3
1 1

2 3
999999999 1000000000
**/