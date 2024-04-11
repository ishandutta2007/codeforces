#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int n, r;

string ans;
int gcd(int a, int b) { return b?gcd(b,a%b):a; }

int gcdcnt(int a, int b) {
  if (a<b) swap(a,b);
  if (b==0) return 0;
  return a/b+gcdcnt(b, a%b);
}

string gcdstr(int a, int b, bool t) {
  if (a<b) swap(a,b);
  if (b==0) return "";
  return gcdstr(b, a%b, !t)+string(a/b, t?'T':'B');
}

int miss(string s) {
  int r=0;
  for (int i=1; i<(int)s.size(); i++) if (s[i]==s[i-1]) r++;
  return r;
  
}

int main(){
  scanf("%d%d", &n, &r);
  if (n==1 && r==1) {
    puts("0\nT");
    return 0;
  }
  ans="";
  int cnt=2*n;
  for (int i=1; i<r; i++) {
    if (gcd(i,r)==1 && gcdcnt(i,r)==n) {
      string tmp, tmp2;
      tmp2=tmp=gcdstr(i,r,1);
      for (int j=0; j<n; j++) tmp2[j]=(tmp[j]=='T'?'B':'T');
      if (tmp[0]=='B') tmp[0]='T';
      if (tmp2[0]=='B') tmp2[0]='T';
      int c=miss(tmp);
      if (ans[0]=='I' || cnt>c) {
	cnt=c;
	ans=tmp;
      }
      c=miss(tmp2);
      if (ans[0]=='I' || cnt>c) {
	cnt=c;
	ans=tmp2;
      }
    }
  }
  if (cnt==2*n) puts("IMPOSSIBLE");
  else  {
    cout<<cnt<<endl;
    cout<<ans<<endl;
  }
  return 0;
}