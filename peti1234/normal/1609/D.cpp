#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, m, si[c], db[c], ki[c], kor=1;
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        si[i]=1;
        db[1]++;
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        a=holvan(a), b=holvan(b);
        if (a==b) kor++;
        else {
            db[si[a]]--, db[si[b]]--;
            si[a]+=si[b];
            db[si[a]]++;
            ki[b]=a;
        }
        int cnt=0, sum=0;
        for (int i=n; i>=1; i--) {
            int s=min(kor-cnt, db[i]);
            sum+=s*i, cnt+=s;
        }
        cout << sum-1 << "\n";
    }
    return 0;
}