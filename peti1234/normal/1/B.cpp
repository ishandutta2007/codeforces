#include <bits/stdc++.h>

using namespace std;
int w, n;
bool x;
string s;
bool b (char c) {return c-'A'>=0 && c-'A'<=25;}
bool sz(char c) {return c-'0'>=0 && c-'0'<=9;};
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> s, n=s.size(), x=0;
        for (int i=1; i<n; i++) if(b(s[i]) && sz(s[i-1])) x=true;
        char c='A';
        if (x) {
            int a=0, b=0,  q=1;
            while(sz(s[q])) a*=10, a+=s[q]-'0', q++;
            q++;
            while(q<n) b*=10, b+=s[q]-'0', q++;
            string k;
            while(b) b--, k+=c+b%26, b/=26;
            reverse(k.begin(), k.end());
            cout << k << a << "\n";
        } else {
            int a=0, bb=0, q=0;
            while(b(s[q])) a*=26, a+=s[q]-'A', a++, q++;
            while(q<n) bb*=10, bb+=s[q]-'0', q++;
            cout << "R" << bb << "C" << a << "\n";
        }
    }
    return 0;
}