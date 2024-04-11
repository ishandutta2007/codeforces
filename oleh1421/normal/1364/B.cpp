//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=100010;
int p[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    vector<int>v;
    for (int i=1;i<=n;i++){
        if (v.size()<=1){
            v.push_back(p[i]);
        } else {
            int last=v.back();
            v.pop_back();
            if ((v.back()<last && last>p[i]) || (v.back()>last && last<p[i])) v.push_back(last);
            v.push_back(p[i]);
        }
    }
    cout<<v.size()<<endl;
    for (auto i:v) cout<<i<<" ";
    cout<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
3 4
1 3
5
9 2 7 7
6 1 0 9
4 7 4 6
*/