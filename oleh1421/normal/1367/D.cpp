//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef unsigned long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=300010;
int cnt[30];
int b[N];
int ans[N];
void solve(){
    string s;cin>>s;
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>b[i],ans[i]=-1;
    for (auto i:s){
        cnt[i-'a']++;
    }
    int pos=26;
    int not_answered=n;
    while (not_answered){
        vector<int>v;
        for (int i=1;i<=n;i++){
            if (b[i]==0 && ans[i]==-1) {
                v.push_back(i);
            }
        }
//       cout<<v.size()<<endl;
        while (cnt[pos]<v.size()) {
            pos--;
        }
        for (auto i:v) {
            ans[i]=pos;
            not_answered--;
        }
        for (int i=1;i<=n;i++){
            if (ans[i]==-1){
                for (auto j:v){
                    b[i]-=abs(i-j);
                }
            }
        }
        pos--;
//        cout<<not_answered<<endl;
    }
    for (int i=0;i<=30;i++) cnt[i]=0;
    for (int i=1;i<=n;i++) cout<<char(ans[i]+'a');
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
abba
3
1 0 1
*/