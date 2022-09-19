#include <bits/stdc++.h>

using namespace std;
const int c=500002;
priority_queue<pair<int, int> > q;
int n, kezd, ert;
bool v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a;
        if (a==1) {
            ert++;
            cin >> b;
            q.push({b, -ert});
        }
        if (a==2) {
            kezd++;
            while(v[kezd]) {
                kezd++;
            }
            cout << kezd << " ";
            v[kezd]=1;
        }
        if (a==3) {
            while(true) {
                int id=-q.top().second;
                q.pop();
                if (!v[id]) {
                    cout << id << " ";
                    v[id]=1;
                    break;
                }
            }
        }
    }
    return 0;
}