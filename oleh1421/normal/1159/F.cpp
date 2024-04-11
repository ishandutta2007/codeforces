#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define int ll
using namespace std;
const int N=200010;
const int K=210;
const ll mod=1000000007;
const ld eps=1e-8;
const ld PI=3.1415926535897932384626433832795;
ld S(pair<ld,ld>A,pair<ld,ld>B,pair<ld,ld>C){
    return (B.first-A.first)*(B.second+A.second)+(C.first-B.first)*(C.second+B.second)+(A.first-C.first)*(A.second+C.second);
}
pair<ld,ld> p[N];
bool del[N];
int32_t main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    int ind=1;
    for (int i=2;i<=n;i++){
        if (p[i].first<p[ind].first) ind=i;
    }
    string s;cin>>s;
    s=s+"L";
    del[ind]=true;
    vector<int>ans={ind};
    for (auto cur:s){
        int nxt=-1;
        if (cur=='L'){
            for (int i=1;i<=n;i++){
                if (del[i]) continue;
                if (nxt==-1 || S(p[ind],p[i],p[nxt])<0) nxt=i;
            }
        } else {
            for (int i=1;i<=n;i++){
                if (del[i]) continue;
                if (nxt==-1 || S(p[ind],p[i],p[nxt])>0) nxt=i;
            }
        }
        ans.push_back(nxt);
        del[nxt]=true;
        ind=nxt;
    }
    for (int i:ans) cout<<i<<" ";
    cout<<endl;
    return 0;

}

/**
1 2 3
6
A 5 6 7
A 3 10 17
R 1
A 15 18 21
A 5 10 15
R 3

10 3
-5 -4 -3 -2 -1 0 1 2 3 4
1 0 4 1
1 5 9 1
2 0 9 3
**/