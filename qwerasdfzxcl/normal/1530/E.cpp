#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int cnt[50];

void solve2(int x){
    int n = 0;
    for (int i=0;i<26;i++) n += cnt[i];
    string ans;
    if (n-cnt[x]+2<cnt[x]){
        int val = 0;
        for (int i=0;i<26;i++) if (i!=x && cnt[i]) val++;
        ans.push_back('a'+x);
        cnt[x]--;
        int idx = -1;
        for (int i=0;i<26;i++) if (i!=x && cnt[i]){
            idx = i;
            ans.push_back('a'+i);
            cnt[i]--;
            break;
        }

        if (val==1){
            for (int j=0;j<cnt[idx];j++) ans.push_back('a'+idx);
            for (int j=0;j<cnt[x];j++) ans.push_back('a'+x);
        }

        else{
            for (int j=0;j<cnt[x];j++) ans.push_back('a'+x);
            for (int i=0;i<26;i++) if (i!=x && i!=idx && cnt[i]){
                ans.push_back('a'+i); cnt[i]--; break;
            }
            for (int i=0;i<26;i++) if (i!=x){
                for (int j=0;j<cnt[i];j++) ans.push_back('a'+i);
            }
        }
        cout << ans << '\n';
        return;
    }

    string tmp;
    int pt = 0;
    for (int i=0;i<26;i++) if (i!=x){
        for (int j=0;j<cnt[i];j++) tmp.push_back('a'+i);
    }
    ans.push_back('a'+x);
    ans.push_back('a'+x);
    for (int i=2;i<cnt[x];i++){
        ans.push_back(tmp[pt]);
        ans.push_back('a'+x);
        pt++;
    }
    assert(pt<=(int)tmp.size());
    for (;pt<(int)tmp.size();pt++) ans.push_back(tmp[pt]);
    cout << ans << '\n';
}

void solve(){
    ///init
    for (int i=0;i<26;i++) cnt[i] = 0;
    ///
    string s;
    cin >> s;
    int n = s.size();
    bool flag = 1;
    for (int i=0;i<n;i++){
        cnt[s[i]-'a']++;
        if (i && s[i-1]!=s[i]) flag = 0;
    }
    if (flag){
        cout << s << '\n'; return;
    }
    for (int i=0;i<26;i++) if (cnt[i]==1){
        cout << (char)('a'+i);
        string t;
        for (int j=0;j<n;j++) if (s[j]!='a'+i) t.push_back(s[j]);
        sort(t.begin(), t.end());
        cout << t << '\n';
        return;
    }

    for (int i=0;i<26;i++) if (cnt[i]){
        solve2(i); return;
    }

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}