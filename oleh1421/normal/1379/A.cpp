#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100010;
const ll mod=1000000007ll;
string t="abacaba";
string s,s1;
bool ok(int i){
    for (int j=0;j<t.size();j++){
        if (s[i+j]!='?' && s[i+j]!=t[j]) return false;
    }
    return true;
}
bool ok1(int i){
    for (int j=0;j<t.size();j++){
        if (s1[i+j]!=t[j]) return false;
    }
    return true;
}
void solve(){
    int n;cin>>n;
    cin>>s;

    for (int i=0;i+t.size()<=s.size();i++){
        s1=s;
        if (!ok(i)) continue;
        for (int j=0;j<t.size();j++){
            s1[i+j]=t[j];
        }
        int cnt=0;
        for (int j=0;j+t.size()<=s.size();j++){
            cnt+=ok1(j);
        }
        if (cnt==1){
            for (int j=0;j<s1.size();j++){
                if (s1[j]=='?') s1[j]='x';
            }
            cout<<"Yes\n";
            cout<<s1<<endl;
            return;
        }

    }
    cout<<"No\n";
}
int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}