#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int n,i,j,k,m;
char ss[111],c;
bool a[111];
string s[111],t;
bool eq(string a, string b) {
  for (int i=0; i<a.length(); i++) if (a[i]<='Z') a[i]=a[i]-'A'+'a';
  for (int i=0; i<b.length(); i++) if (b[i]<='Z') b[i]=b[i]-'A'+'a';
  return a==b;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%s",ss); s[i]=ss; }
  scanf("%s",ss); t=ss; m=t.length();
  scanf("%s",ss); c=ss[0];
  for (i=0; i<m; i++) for (j=0; j<n; j++) if (i+s[j].length()<=m && eq(s[j],t.substr(i,s[j].length())))
    for (k=0; k<s[j].length(); k++) a[i+k]=true;
  for (i=0; i<m; i++) if (a[i]) {
    if (c=='a') {
	  if (t[i]==c) t[i]='b'; else if (t[i]=='A') t[i]='B'; else if (t[i]<='Z') t[i]='A'; else t[i]='a';
	} else if (t[i]==c) t[i]='a';
	  else if (t[i]==c-'a'+'A') t[i]='A'; else if (t[i]<='Z') t[i]=c-'a'+'A'; else t[i]=c;
  }
  puts(t.c_str());
  return 0;
}