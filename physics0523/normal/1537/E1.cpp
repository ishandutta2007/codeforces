#include<bits/stdc++.h>

using namespace std;

//https://ei1333.github.io/algorithm/suffix-array.html
struct SuffixArray{
  vector< int > SA;
  string s;

  void Build_SA(const string& str)
  {
    s = str;
    SA.resize(s.size());
    iota(begin(SA), end(SA), 0);
    sort(begin(SA), end(SA), [&](const int& a, const int& b)
    {
      if(s[a] == s[b]) return(a > b);
      return (s[a] < s[b]);
    });
    vector< int > classes(s.size()), c(s.size()), cnt(s.size());
    for(int i = 0; i < s.size(); i++) {
      c[i] = s[i];
    }
    for(int len = 1; len < s.size(); len <<= 1) {
      for(int i = 0; i < s.size(); i++) {
        if(i > 0 && c[SA[i - 1]] == c[SA[i]] && SA[i - 1] + len < s.size() && c[SA[i - 1] + len / 2] == c[SA[i] + len / 2]) {
          classes[SA[i]] = classes[SA[i - 1]];
        } else {
          classes[SA[i]] = i;
        }
      }
      iota(begin(cnt), end(cnt), 0);
      copy(begin(SA), end(SA), begin(c));
      for(int i = 0; i < s.size(); i++) {
        int s1 = c[i] - len;
        if(s1 >= 0) SA[cnt[classes[s1]]++] = s1;
      }
      classes.swap(c);
    }
  }

  int operator[](int k) const
  {
    return (SA[k]);
  }

  int size() const
  {
    return (s.size());
  }

  bool lt_substr(string& t, int si = 0, int ti = 0)
  {
    int sn = s.size(), tn = t.size();
    while(si < sn && ti < tn) {
      if(s[si] < t[ti]) return (true);
      if(s[si] > t[ti]) return (false);
      ++si, ++ti;
    }
    return (si >= sn && ti < tn);
  }

  int lower_bound(string& t)
  {
    int low = -1, high = SA.size();
    while(high - low > 1) {
      int mid = (low + high) >> 1;
      if(lt_substr(t, SA[mid])) low = mid;
      else high = mid;
    }
    return (high);
  }

  pair< int, int > lower_upper_bound(string& t)
  {
    int idx = lower_bound(t);
    int low = idx - 1, high = SA.size();
    t.back()++;
    while(high - low > 1) {
      int mid = (low + high) >> 1;
      if(lt_substr(t, SA[mid])) low = mid;
      else high = mid;
    }
    t.back()--;
    return (make_pair(idx, high));
  }

  void output()
  {
    for(int i = 0; i < size(); i++) {
      cout << i << ": " << s.substr(SA[i]) << endl;
    }
  }
};

int main(){
  int n,m;
  string s;
  cin >> n >> m >> s;
  SuffixArray sa;
  s.push_back('z'+1);
  sa.Build_SA(s);
  s.pop_back();
  int tg=n;
  for(int i=0;i<n;i++){
    if(sa[i]==0){
      for(int j=i+1;j<n;j++){
        tg=min(sa[j],tg);
      }
    }
  }
  //cerr << tg << '\n';
  for(int i=0;i<m;i++){
    cout << s[i%tg];
  }cout << '\n';
  return 0;
}