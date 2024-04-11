// https://codeforces.com/contest/1610/submission/137339219
#include<bits/stdc++.h>

using namespace std;

int n, kov[300005];
string s;
vector<int> sz;
bool sm(int a, int b) {
    int bb=b;
    while (a<bb && b<n && s[a]==s[b]) {
        a=kov[a+1], b=kov[b+1];
    }
    return (b<n && s[a]<=s[b]);
}
int main()
{
    cin >> s;
    n=s.size();
    sz.push_back(n), kov[n]=n;
    for (int i=n-1; i>=0; i--) {
        if (s[i]=='(') {
            kov[i]=i;
            sz.pop_back();
            if (sz.size()==0) {
                sz.push_back(i);
            } else if (sm(i, sz.back())) {
                sz.back()=i;
            } else {
                kov[i]=sz.back();
            }
        } else {
            sz.push_back(i), kov[i]=i;
        }
    }
    int pos=0;
    while (pos<n) {
        cout << s[pos];
        pos=kov[pos+1];
    }
    cout << "\n";
	return 0;
}