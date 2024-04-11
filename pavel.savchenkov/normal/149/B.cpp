#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int to(string s,int k)
{
    int res = 0;
    int n = (int)s.length();
    int p = 1;
    for (int i=n-1; i>=0; i--)
    {
        if (s[i]>='A' && s[i]<='Z' && s[i]-'A'+10 > k-1) return -1;
         else if (s[i]-'0' > k-1 && s[i]>='0' && s[i]<='9') return -1;
        if (s[i]>='A' && s[i]<='Z') res+=(s[i]-'A'+10)*p;
         else res+=(s[i]-'0')*p;
        p*=k;
    }
    return res;
}

string go(string a)
{
 for (int i=0; i<(int)a.length(); i++) 
  if (a[i]!='0') return a.substr(i,(int)a.length()-i+1);
 return "0";     
};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string a = ""; string b = "";
    char c;
    while (c!=':') { scanf("%c",&c); if (c!=':') a+=c; }
    cin >> b;
    a = go(a); b = go(b);
    if ((int)a.length() == 1)
    {
       if (a[0]>='0' && a[0]<='9' && a[0]-'0' >= 24) { cout << "0"; return 0; }
       if (a[0]>='A' && a[0]<='Z' && a[0]-'A'+10 >= 24) { cout << "0"; return 0; }
    }
    
    if  ((int)a.length() <= 1 && (int)b.length()<=1 ) { cout << "-1"; return 0; }
    bool was = false;
    for (int i=2;; i++)
    {
        int ta = to(a,i);
        int tb = to(b,i);
      //  cout << ta << " " << tb << endl;
        if (ta>=0 && ta<24 && tb>=0 && tb<60) { cout << i << " "; was = true; }
        if (ta >= 24 || tb >= 60) break;
    }
    if (!was) cout << "0";
    return 0;
}