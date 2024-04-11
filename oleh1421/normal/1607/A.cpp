#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
int a[N],b[N],m[N];
map<int,vector<int> >mp;
int p[26];
void solve(){
    string s;cin>>s;
    for (int i=0;i<s.size();i++){
        p[s[i]-'a']=i;
    }
    string t;cin>>t;
    int res=0;
    for (int i=1;i<t.size();i++){
        res+=abs(p[t[i]-'a']-p[t[i-1]-'a']);
    }
    cout<<res<<endl;


}
int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
2 2
1 3
4 2
**/