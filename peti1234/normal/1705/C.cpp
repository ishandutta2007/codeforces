#include <bits/stdc++.h>

using namespace std;
void solve() {
    long long n, c, q, sum, l[45], r[45];
    string s;
    vector<long long> len;
    cin >> n >> c >> q;
    sum=n;
    len.push_back(sum);
    cin >> s;
    for (int i=1; i<=c; i++) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
        sum+=r[i]-l[i]+1;
        len.push_back(sum);
    }
    while (q--) {
        long long pos;
        cin >> pos;
        pos--;
        for (int i=c-1; i>=0; i--) {
            if (pos>=len[i]) {
                pos=l[i+1]+pos-len[i];
                //cout << "valt " << pos << "\n";
            }
        }
        cout << s[pos] << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
4 3 1
mark
1 4
5 7
3 8
12
*/