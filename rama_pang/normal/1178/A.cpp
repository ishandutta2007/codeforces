#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define db(x) cout << "==========>> " << #x << " is " << x << endl
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i,j) FOR(i,0,j,1)
#define RREP(i,j) RFOR(i,j,0,1)
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
#define all(cont) cont.begin(), cont.end()
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP make_pair
#define PB push_back
using namespace std;
ll N,total,arr,total2;
int main (){

    cin>>N;
    cin >> arr;
    total=arr;
    total2=arr;
    vector<int> ans;
    ans.PB(1);
    FOR(i,2,N+1,1){
        int a;cin>>a;
        if (2*a<=arr){
            ans.PB(i);
            total+=a;
        }
        total2+=a;
    }
    if (total*2<=total2){
        cout << "0\n";
        return 0;
    }
    cout << ans.size() << endl;
    REP(i,ans.size()){
        if (i>0) cout << " ";
        cout << ans[i];
    }
    if(ans.size()>0) cout<< endl;
}