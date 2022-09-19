#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int w, n, m, t[c], db[c];
vector<int> ans;
bool v[c];
void dfs(int a, int b) {
    v[a]=true;
    int s=a+b;
    if (s>n) {
        s-=n;
    }
    if (!v[t[s]]) {
        dfs(t[s], b);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            int s=(i-t[i]+n)%n;

            db[s]++;
        }
        for (int s=0; s<n; s++) {
            if (4*db[s]>=n) {
                int kor=0;
                for (int i=1; i<=n; i++) {
                    v[i]=0;
                }
                for (int i=1; i<=n; i++) {
                    if (!v[i]) {
                        kor++;
                        dfs(i, s);
                    }
                }
                if (m+kor>=n) {
                    ans.push_back(s);
                }
            }
        }
        cout << ans.size() << "\n";
        for (auto x:ans) {
            cout << x << " ";
        }
        cout << " ";
        for (int i=0; i<n; i++) {
            db[i]=0;
        }
        ans.clear();
    }
    return 0;
}