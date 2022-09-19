#include <bits/stdc++.h>

using namespace std;
int n;
vector<char> c;
string s;
string p;
string f;
int t[10001];
char l[10001];
char q='a';
int k=0;
int main()
{
    cin >> f;
    n=f.size();
    for (int i=0; i<26; i++) {
        char x='a';
        c.push_back(x+i);
    }
    for (int i=1; i<=n; i++) {
        s+=q+k;
        k++;
        k=k%26;
    }
    cout.flush() << "? " << s << endl;
    cin >> p;
    s.clear();
    k=0;
    for (int i=0; i<p.size(); i++) {
        t[i+1]+=p[i]-'a';
        //cout << t[i+1] << " ";
    }
    for (int i=1; i<=n; i++) {
        s+=q+k;
        if (i%26==0) {
            k++;
        }
        k=k%26;
    }
    p.clear();
    cout.flush() << "? " << s << endl;
    cin >> p;
    k=0;
    for (int i=0; i<p.size(); i++) {
        t[i+1]+=(p[i]-'a')*26;
    }
    p.clear();
    s.clear();
    for (int i=1; i<=n; i++) {
        s+=q+k;
        if (i%(26*26)==0) {
            k++;
        }
        k=k%26;
    }
    cout.flush() << "? " << s << endl;
    cin >> p;
    for (int i=0; i<p.size(); i++) {
        t[i+1]+=(p[i]-'a')*26*26;
    }
    cout << "! ";
    for (int i=1; i<=n; i++) {
        l[t[i]]=f[i-1];
    }
    for (int i=0; i<n; i++) {
        cout << l[i];
    }
    cout << endl;
    return 0;
}