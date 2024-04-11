#include <bits/stdc++.h>

using namespace std;
int n, m, jo, unk=-1;
string s;

int main()
{
    cin >> n >> m >> s;
    m=min(m, n);
    for (int i=0; i<m; i++) if (s[i]!='9') unk=i;
    for (int i=m; i<n; i++) {
        if (s[i]<s[i-m]) jo=1;
        if (s[i]>s[i-m] && !jo) {
            s[unk]++, jo=1;
            for (int i=unk+1; i<m; i++) s[i]='0';
        }
    }
    cout << n << "\n";
    for (int i=0; i<m; i++) cout << s[i];
    for (int i=m; i<n; i++) s[i]=s[i-m], cout << s[i];

    return 0;
}