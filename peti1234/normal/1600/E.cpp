#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, t[c], bal=1, jobb=1, l, r, id, ut=-1;
void res(int id) {
    cout << (id ? "Bob" : "Alice") << "\n";
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<n; i++) {
        if (t[i+1]>t[i]) {
            bal++;
        } else {
            break;
        }
    }
    for (int i=n-1; i>=1; i--) {
        if (t[i]>t[i+1]) {
            jobb++;
        } else {
            break;
        }
    }
    l=1, r=n;
    while (true) {
        if (l>r || ut>=max(t[l], t[r])) {
            res(1-id);
        }
        if (t[l]==t[r]) {
            if (bal%2==0 && jobb%2==0) id=1-id;
            res(id);
        }
        if (t[l]>t[r]) {
            if (bal%2) res(id);
            else if (t[r]>ut) {
                ut=t[r];
                r--;
                jobb--;
            } else res(1-id);
        } else {
            if (jobb%2) res(id);
            else if (t[l]>ut) {
                ut=t[l];
                l++;
                bal--;
            } else res(1-id);
        }
        id=1-id;
    }
    return 0;
}