#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n;

int a[26][26];

int main(){
  scanf("%d", &n);
  string s;
  for (int i=0; i<n; i++) {
    cin>>s;
    int f=s[0]-'a', b=s[s.size()-1]-'a';
    for (int i=0; i<26; i++)
      if (a[i][f]) a[i][b]=max(a[i][b], int(a[i][f]+s.size()));

    a[f][b]=max(a[f][b], int(s.size()));
  }    
  int ans=0;
  for (int i=0; i<26; i++) ans=max(ans, a[i][i]);
  printf("%d\n", ans);
  return 0;
}