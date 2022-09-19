#include <bits/stdc++.h>
 
using namespace std;
vector<long long> q;
long long r=1;
long long of;
long long ans=0;
int n;
int main()
{
    cin >> n;
    of=(long long)1<<32;
    of--;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        if (s=="add") {
            ans+=r;
            if (ans>of) {
                cout << "OVERFLOW!!!" << endl;
                return 0;
            }
        }
        if (s=="end") {
            if (q.back()>0) {
                r/=q.back();
            }
            q.pop_back();
        }
        if (s=="for") {
            long long k;
            cin >> k;
            if (r<of) {
                r*=k;
                q.push_back(k);
            }
            else {
                q.push_back(-k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}