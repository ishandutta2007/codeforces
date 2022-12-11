#include <bits/stdc++.h>

using namespace std;

int cnt[26];

int main(){
        int n;
        cin >> n;
        char val[n];
        cin >> val;
        set<char>tell;
        for(int a = 'a';a<='z';a++)tell.insert(a);
        for(char x : val)tell.erase(x);
        set<char>ist;
        vector<string>cons;
        int m;
        cin >> m;
        string cur;
        bool sh = false;
        for(int j = 0;j<m;j++){
                cin >> cur;
                sh = true;
                for(int i = 0;i<cur.size();i++){
                        if((tell.count(cur[i]) == 0 && val[i] == '*') || (val[i] != '*' && cur[i] != val[i]))sh=false;
                }
                if(sh==true)cons.push_back(cur);
        }
        for(auto x : cons){
                for(int j = 0;j<x.size();j++)ist.insert(x[j]);
                for(auto l : ist)cnt[l-97]++;
                ist.clear();
        }
        int ans = 0;
        for(auto x : tell) if(cnt[x-97]>=cons.size()) ans++;
        cout << ans;
        return 0;
}