#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int t[c][c], mini=1e9;
int ask(int a, int b) {
    if (!t[a][b]) {
        cout.flush() << "? " << a << " " << b << "\n";
        int x; cin >> x;
        t[a][b]=x, mini=min(mini, x);
    }
    return t[a][b];
}
vector<int> reduce(vector<int> row, vector<int> col) {
    vector<int> ans;
    int i=0, si=row.size();
    for (int c:col) {
        if (ans.size()==0) {
            ask(row[i], c);
            ans.push_back(c);
            continue;
        }
        while(ans.size()>0 && ask(row[i], ans.back())>ask(row[i], c)) {
            ans.pop_back();
            i--;
        }
        if (i+1<si) {
            ans.push_back(c);
            i++;
        }
    }
    return ans;
}
vector<int> solve(vector<int> row, vector<int> col) {
    int n=row.size(), m=col.size();
    if (m>n) col=reduce(row, col), m=col.size();
    vector<int> nrow, nans, ans;
    for (int i=1; i<n; i+=2) {
        nrow.push_back(row[i]);
    }
    if (nrow.size()>0) nans=solve(nrow, col);
    nans.push_back(col[m-1]);
    int el=col[0], kov, pos;
    for (int i=0; i<n; i++) {
        if (i%2) ans.push_back(nans[i/2]);
        else {
            kov=nans[i/2], pos=el;
            for (int j=0; j<col.size(); j++) {
                int x=col[j];
                if (el<=x && x<=kov && ask(row[i], x)<ask(row[i], pos)) pos=x;
            }
            el=kov;
            ans.push_back(pos);
        }
    }
    return ans;
}
int main()
{
    int n, m;
    vector<int> row, col;
    cin >> n >> m;
    for (int i=1; i<=n; i++) row.push_back(i);
    for (int i=1; i<=m; i++) col.push_back(i);
    solve(row, col);
    cout << "! " << mini << "\n";
	return 0;
}
/*
2 3
2 3 3 1 1
*/