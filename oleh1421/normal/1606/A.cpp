//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
const ll mod=1000000007;
bool ok(string t){
    int res=0;
    for (int i=1;i<t.size();i++){
        if (t[i]!=t[i-1]){
            if (t[i]=='a') res++;
            else res--;
        }
    }
    return (res==0);
}
void solve(){
    string s;cin>>s;
    if (ok(s)){
        cout<<s<<endl;
        return;
    }
    for (int i=0;i<s.size();i++){
        string t=s;
        if (s[i]=='a') t[i]='b';
        else t[i]='a';
        if (ok(t)){
            cout<<t<<endl;
            return;
        }
    }

}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//6 3 7 5 6
/**
7 1 2
2 15 6 3 7 5 6
3 5
1
**/