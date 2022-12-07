#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  string s; cin >> s;
  map < char, int > cnt;
  for(auto &c : s) ++cnt[c];

  char cur = 'a';
  for(auto &p : cnt) if(p.second > cnt[cur]) cur = p.first;

  vector < int > pos;
  for(int i = 0; i < s.size(); ++i) {
    if(s[i] == cur) pos.push_back(i);
  }

  vector < bool > taken(s.size(), false);

  for(int i = 0; i + i < pos.size(); ++i) {
    int x = pos[i], y = pos[pos.size() - i - 1];
    taken[x] = taken[y] = 1;
    if(x == y) break;
    if(pos[i + 1] == y) {
      map < char, int > cntChar; 
      for(int id = x + 1; id < y; ++id) {
        ++cntChar[s[id]];
      }

      char res = 'a'; 
      for(char w = 'a'; w <= 'c'; ++w) {
        if(cntChar[w] > cntChar[res]) res = w;
      }

      for(int id = x + 1; id < y; ++id) {
        if(s[id] == res) taken[id] = 1;
      }
    }
    else {
      map < char, int > cntLeft, cntRight; 
      for(int id = x + 1; id < pos[i + 1]; ++id) ++cntLeft[s[id]];
      for(int id = y - 1; id > pos[pos.size() - i - 2]; --id) ++cntRight[s[id]];

      char res = 'a'; int best = min(cntLeft['a'], cntRight['a']);

      for(char w = 'a'; w <= 'c'; ++w) {
        if(min(cntLeft[w], cntRight[w]) > best) {
          best = min(cntLeft[w], cntRight[w]);
          res = w;
        }
      }

      for(int id = x + 1, cnt = best; id < pos[i + 1]; ++id) {
        if(s[id] == res && cnt-- > 0) taken[id] = 1;
      }
      for(int id = y - 1, cnt = best; id > pos[pos.size() - i - 2]; --id) {
        if(s[id] == res && cnt-- > 0) taken[id] = 1;
      }
    }
  }

  for(int i = 0; i < s.size(); ++i) if(taken[i]) cout << s[i];

  return 0;
}