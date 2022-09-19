#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, ans[c], el;
bool  v[c];
vector<int> hiany;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> ans[i];
        if (ans[i]) {
            v[ans[i]]=1;
        }
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            hiany.push_back(i);
        }
    }
    for (int i=1; i<=n; i++) {
        if (!ans[i]) {
            int ut=hiany.back();
            if (i!=ut) {
                ans[i]=ut;
                hiany.pop_back();
            } else {
                if (el) {
                    ans[i]=ut;
                    swap(ans[i], ans[el]);
                    hiany.pop_back();
                } else {
                    hiany.pop_back();
                    int ue=hiany.back();
                    hiany.pop_back();
                    ans[i]=ue;
                    hiany.push_back(ut);
                }
            }
            el=i;
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}