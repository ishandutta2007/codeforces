#include <bits/stdc++.h>

using namespace std;
string s;
long long n, cnt, ans;
priority_queue<pair<long long, int> > q;
vector<int> p;
int main()
{
    cin >> s;
    n=s.size();
    for (int i=0; i<n; i++) {
        if (s[i]=='(') cnt++;
        if (s[i]==')') cnt--;
        if (s[i]=='?') {
            long long a, b;
            cin >> a >> b;
            ans+=b;
            cnt--;
            q.push({b-a, i});
        }
        if (cnt<0) {
            if (q.size()==0) {
                cout << -1 << "\n";
                return 0;
            }
            ans-=q.top().first;
            p.push_back(q.top().second);
            q.pop();
            cnt+=2;
        }
    }
    if (cnt!=0) {
        cout << -1 << "\n";
        return 0;
    }
    cout << ans << "\n";
    for (auto x:p) {
        s[x]='(';
    }
    for (int i=0; i<n; i++) {
        cout << (s[i]=='(' ? '(' : ')');
    }
    cout << "\n";
    return 0;
}