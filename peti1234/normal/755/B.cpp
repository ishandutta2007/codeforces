#include <bits/stdc++.h>

using namespace std;
int n, m;
int a=0;
vector<string> pb;
vector<string> eb;
int main()
{
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        string x;
        cin >> x;
        pb.push_back(x);
    }
    for (int i=1; i<=m; i++) {
        string x;
        cin >> x;
        eb.push_back(x);
    }
    if (n>m) {
        cout << "YES" << endl;
        return 0;
    }
    if (m>n) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i=0; i<pb.size(); i++) {
        for (int j=0; j<eb.size(); j++) {
            if (pb[i]==eb[j]) {
                a++;
            }
        }
    }
    if (a%2==0) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }

    return 0;
}