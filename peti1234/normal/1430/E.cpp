#include <bits/stdc++.h>
#define lsb(a) (a)&(-a);
using namespace std;
const int c=200002;
int n, t[c], p[c];
long long sum;
string s;
vector<int> a[32], b[32];
int ask(int a) {
    int ans=0;
    while(a>0) {
        ans+=t[a], a-=lsb(a);
    }
    return ans;
}
void add(int a) {
    while(a<=n) {
        t[a]++, a+=lsb(a);
    }
}
int main()
{
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        int x=s[i]-'a'+1;
        a[x].push_back(i+1), b[x].push_back(n-i);
    }
    for (int i=0; i<30; i++) reverse(b[i].begin(), b[i].end());
    for (int i=0; i<30; i++) {
        for (int j=0; j<a[i].size(); j++) {
            p[a[i][j]]=b[i][j];
        }
    }
    for (int i=n; i>=1; i--) {
        sum+=ask(p[i]);
        add(p[i]);
    }
    cout << sum << "\n";
    return 0;
}