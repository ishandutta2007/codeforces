//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef unsigned long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=300010;
int cnt[N];
vector<int>g[N];
int used[N];
vector<int>ans;
int n,m;
vector<int>cur;
bool solved=true;
void F(int v){
    if (solved) return;
    if (cur.size()*7>n*4) return;
    if (v==n+1){
        ans=cur;
        solved=true;
        return;
    }
    if (!used[v]){
        for (auto to:g[v]){
            if (cnt[v]) used[to]++;
            else cnt[to]++;
        }
        F(v+1);
        for (auto to:g[v]){
            if (cnt[v]) used[to]--;
            else cnt[to]--;
        }
        if (rand()%2){
            cur.push_back(v);
            F(v+1);
            cur.pop_back();
        }
    } else {
        cur.push_back(v);
        F(v+1);
        cur.pop_back();
    }


}
void solve(){
    solved=false;
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
//        cnt[y]++;
    }
    F(1);

//    vector<int>ans1;

//    if (ans.size()*7>n*4){
//        for (int i=1;i<=n;i++) used[i]=true;
//        for (auto i:ans){
//            used[i]=false;
//        }
//        ans.clear();
//        for (int i=1;i<=n;i++){
//            if (used[i]){
//                ans.push_back(i);
//                for (auto to:g[i]){
//                    cnt[to]--;
//                }
//            }
//        }
//        for (int i=1;i<=n;i++){
//            if (used[i]) continue;
//            int sum=0;
//            for (auto to:g[i]){
//                if (!used[to]) sum++;
//            }
//            if (sum && cnt[i]){
//                ans.push_back(i);
//                for (auto to:g[i]) cnt[to]--;
//            }
//        }
//    }


    for (int i=0;i<=n+1;i++){
        g[i].clear();
        cnt[i]=0;
        used[i]=false;
    }
    cout<<ans.size()<<endl;
    for (auto i:ans) cout<<i<<" ";
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
1
10 17
1 2
1 3
2 3
2 4
3 4
3 5
4 5
4 6
5 6
5 7
6 7
6 8
7 8
7 9
8 9
8 10
9 10
*/