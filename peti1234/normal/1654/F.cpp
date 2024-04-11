#include <bits/stdc++.h>

using namespace std;
int n, n2, cnt, ert[1<<18][19];
vector<int> sz;
string s;
bool cmp(int a, int b) {
    int x=ert[a][cnt], y=ert[b][cnt], s=(1<<cnt);
    return (x<y || x==y && ert[a^s][cnt]<ert[b^s][cnt]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    n2=(1<<n);
    for (int i=0; i<n2; i++) {
        sz.push_back(i);
        ert[i][0]=(s[i]-'a');
    }
    for (int i=1; i<=n; i++) {
        sort(sz.begin(), sz.end(), cmp);
        /*for (auto x:sz) {
            cout << x << " ";
        }
        cout << "\n";*/
        int s=0;
        for (int j=0; j<n2; j++) {
            if (j>0 && cmp(sz[j-1], sz[j])) {
                s++;
            }
            ert[sz[j]][i]=s;
        }
        cnt++;
    }
    for (int i=0; i<n2; i++) {
        cout << s[i^sz[0]];
    }
    return 0;
}
/*
5
ccfcffccccccffcfcfccfffffcccccff
*/