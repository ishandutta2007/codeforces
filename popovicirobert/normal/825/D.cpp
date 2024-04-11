#include <bits/stdc++.h>

using namespace std;

string s, t;
int fr1[26], fr2[26];
int vf[26];

struct Data {
    int cnt1, cnt2;
    char ch;
    bool operator <(const Data &other) const {
        if(cnt2 == 0)
            return 1;
        if(other.cnt2 == 0)
            return 0;
        return cnt1 / cnt2 > other.cnt1 / other.cnt2;
    }
};

priority_queue <Data> pq;

int main() {
    //ifstream cin("C.in");
    //ofstream cout("C.out");
    int i,j;
    ios::sync_with_stdio(false);
    cin >> s >> t;
    int nr = 0;
    for(i = 0; i < s.size(); i++)
      if(s[i] != '?')
        fr1[s[i] - 'a']++;
      else
        nr++;
    for(i = 0; i < t.size(); i++)
      fr2[t[i] - 'a']++;
    for(i = 0; i < 26; i++)
      pq.push({fr1[i], fr2[i], i});
    while(nr > 0) {
       char ch = pq.top().ch;
       int cnt1 = pq.top().cnt1;
       pq.pop();
       pq.push({cnt1 + 1, fr2[ch], ch});
       vf[ch]++;
       nr--;
    }
    j = 0;
    for(i = 0; i < s.size(); i++) {
        if(s[i] == '?') {
            while(j < 26 && vf[j] == 0)
                j++;
            if(vf[j] > 0) {
                vf[j]--;
                s[i] = j + 'a';
                cout << s[i];
            }
        }
        else
            cout << s[i];
    }
    //cin.close();
    //cout.close();
    return 0;
}