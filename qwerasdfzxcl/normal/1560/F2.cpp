#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    auto s = to_string(n);
    for (int i=(int)s.size()-1;i>=-1;i--){
        string ans;
        set<int> st;
        for (int j=0;j<=i;j++){
            st.insert(s[j]-'0');
            ans.push_back(s[j]);
        }
        if ((int)st.size()>k) continue;
        if ((int)st.size()==k){
            if (i+1<(int)s.size()){
                auto iter = st.upper_bound(s[i+1]-'0');
                if (iter==st.end()) continue;
                ans.push_back(*iter+'0');
                for (int j=i+2;j<(int)s.size();j++) ans.push_back(*st.begin()+'0');
            }
        }
        else{
            if (i+1<(int)s.size()){
                if (s[i+1]=='9') continue;
                ans.push_back(s[i+1]+1);
                st.insert(ans.back()-'0');
                if ((int)st.size()==k){
                    for (int j=i+2;j<(int)s.size();j++) ans.push_back(*st.begin()+'0');
                }
                else{
                    for (int j=i+2;j<(int)s.size();j++) ans.push_back('0');
                }
            }
        }
        cout << ans << '\n';
        return;
    }

}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}