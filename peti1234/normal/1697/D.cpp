#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, ans[c], kov[c];
int ask(int a, int b) {
    cout.flush() << "? " << 2 << " " << a << " " << b << endl;
    int x;
    cin >> x;
    return x;
}
int main()
{
    cin >> n;
    for (int i=0; i<26; i++) kov[i]=n+1;
    for (int i=n; i>=1; i--) {
        vector<int> sz;
        for (int j=0; j<26; j++) {
            if (kov[j]<=n) sz.push_back(kov[j]);
        }
        sort(sz.begin(), sz.end());
        int si=sz.size(), lo=-1, hi=si, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (ask(i, sz[mid])>mid+1) lo=mid;
            else hi=mid;
        }
        if (hi==si) {
            cout.flush() << "? " << 1 << " " << i << endl;
            char c;
            cin >> c;
            ans[i]=(c-'a');
        } else {
            ans[i]=ans[sz[hi]];
        }
        kov[ans[i]]=i;
    }
    cout.flush() << "! ";
    for (int i=1; i<=n; i++) {
        cout << (char)('a'+ans[i]);
    }
    cout << endl;
    return 0;
}