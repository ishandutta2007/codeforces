#include <bits/stdc++.h>
#define int int64_t
#define loop(i,s,e) for(int i=s;i<e;i++)

using namespace std;

char dir[] = {'L','R','U','D'};
int32_t main(){
    int n,m,k; cin>>n>>m>>k;
    int a;
    loop(i,0,4*k) cin>>a;
    vector<int> ans;
    loop(i,0,m-1) ans.push_back(0);
    loop(i,0,n-1) ans.push_back(2);
    loop(i,0,n){
        loop(j,0,m-1) ans.push_back((i%2==0?1:0));
        if (i<n-1) ans.push_back(3);
    }
    cout<<ans.size()<<endl;
    for(int x:ans) cout<<dir[x];
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
3 3 2
1 2
2 1
3 3
3 2




------>
<------
------>
<------
*/