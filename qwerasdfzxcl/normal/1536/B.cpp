#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<string> v;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    unordered_set<string> st;
    for (int l=1;l<=3;l++){
        for (int i=0;i<n-l+1;i++){
            string tmp;
            for (int j=i;j<i+l;j++) tmp.push_back(s[j]);
            st.insert(tmp);
        }
    }
    for (auto &s:v) if (st.find(s)==st.end()){
        cout << s << '\n';
        return;
    }

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for (int i=0;i<26;i++){
        string tmp;
        tmp.push_back('a'+i);
        v.push_back(tmp);
    }
    for (int i=0;i<26;i++){
        string tmp;
        tmp.push_back('a'+i);
        v.push_back(tmp);
        for (int j=0;j<26;j++){
            v.back().push_back('a'+j);
            if (j<25) v.push_back(tmp);
        }
    }
    for (int i=0;i<26;i++){
        string tmp;
        tmp.push_back('a'+i);
        v.push_back(tmp);
        for (int j=0;j<26;j++){
            v.back().push_back('a'+j);
            string tmp2 = v.back();
            for (int k=0;k<26;k++){
                v.back().push_back('a'+k);
                if (k<25) v.push_back(tmp2);
            }
            if (j<25) v.push_back(tmp);
        }
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}