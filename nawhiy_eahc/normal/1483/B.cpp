#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[100002], l[100002], r[100002];
vector<int> ans;

int gcd(int x, int y)
{
    if(x < y) swap(x, y);
    if(y == 0) return x;
    return gcd(y, x%y);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, cnt; cin >> n; cnt = n;
        for(int i=1;i<=n;i++) cin >> a[i];
        ans.clear();

        if(n == 1)
        {
            if(a[1] == 1)
            {
                cout << "1 1\n";
            }
            else cout << "0\n";
            continue;
        }

        deque<int> d;
        for(int i=2;i<=n;i++)
        {
            if(gcd(a[i-1], a[i]) == 1) d.push_back(i);
        }
        if(gcd(a[n], a[1]) == 1) d.push_back(1);

        l[1] = n; r[n] = 1;
        for(int i=2;i<=n;i++) l[i] = i-1;
        for(int i=1;i<n;i++) r[i] = i+1;

        while(!d.empty())
        {
            int now = d.front(); d.pop_front();
            int L = l[now], R = r[now];
            if(!d.empty() && d.front() == R) d.pop_front();
            r[L] = R, l[R] = L;
            ans.push_back(now);
            cnt--;
            if(cnt == 1)
            {
                if(a[L] == 1) ans.push_back(L);
                break;
            }

            if(gcd(a[L], a[R]) == 1) d.push_back(R);
        }

        cout << ans.size() << " ";
        for(int i=0;i<ans.size();i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}