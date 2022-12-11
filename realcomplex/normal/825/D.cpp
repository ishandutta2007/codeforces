#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int cnt1[26],cnt2[26];

int main(){

    string s,t;
    cin >> s >> t;
    vector<int>q;
    int minSuit = 1000000;
    for(int i = 0;i<s.size();i++){
        if(s[i] == '?'){
            q.push_back(i);
        }
        else{
            cnt1[s[i]-97]++;
        }
    }
    for(int i = 0;i<t.size();i++){
        cnt2[t[i]-97]++;
    }
    for(int i = 0;i<26;i++){
        if(cnt2[i]>0){
            if(cnt1[i]/cnt2[i]<minSuit){
                minSuit = cnt1[i]/cnt2[i];
            }
        }
    }
    minSuit++;
    while(q.size()>0){
        for(int x = 0;x<26;x++){
            if(cnt2[x]>0){
                while(cnt1[x]/cnt2[x] < minSuit && q.size() > 0){
                    s[q[q.size()-1]] = x+97;
                    q.erase(q.begin()+(q.size()-1));
                    cnt1[x]++;
                }
            }
        }
        minSuit++;
    }
    cout << s;
    return 0;
}