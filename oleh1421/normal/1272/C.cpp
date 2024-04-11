#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
bool used[31];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    string s;cin>>s;
    for (int i=1;i<=k;i++){
        char c;cin>>c;
        used[c-'a']=true;
    }
    int cnt=0;
    ll res=0ll;
    for (auto i:s){
        if (used[i-'a']) cnt++;
        else cnt=0;
        res+=cnt;
    }
    cout<<res;
    return 0;
}