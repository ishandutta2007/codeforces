#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
int div1(int x){
    if (x<0) return (x/2);
    else return (x+1)/2;
}
int div2(int x){
    if (x<0) return (x-1)/2;
    else return (x/2);
}
int32_t main()
{
    int n;cin>>n;
    int cnt=0;
    vector<int>ans;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        if ((x+100000)%2==0) ans.push_back(x/2);
        else if (cnt==0) ans.push_back(div1(x)),cnt++;
        else ans.push_back(div2(x)),cnt--;
    }
    for (auto i:ans) cout<<i<<endl;
    return 0;
}
/*
11 4
WBWBWBBWBWBWBBWWBWB

*/