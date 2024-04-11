#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
unordered_map<int,int>mp;
const int N=210001;
int cn[31];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;cin>>s;
    for (int i=0;i<s.size();i++) cn[s[i]-'a']++;
    ll res=0;
    for (int i=0;i<26;i++){
        res=max(res,cn[i]*1ll);
        for (int j=0;j<26;j++){
            ll sum=0ll;
            int cnt=0;
            for (int t=0;t<s.size();t++){
                if ((s[t]-'a')==j) sum+=cnt*1ll;

                if ((s[t]-'a')==i) cnt++;
            }
            res=max(res,sum);
        }
    }
    cout<<res;
    return 0;
}
/*
4 5 3
3 4
2 4
2 2
3
2 1 4 5
1 2 1 4
2 3 4 4
*/