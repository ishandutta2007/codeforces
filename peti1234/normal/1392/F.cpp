#include <bits/stdc++.h>

using namespace std;
long long n, x, ut, dif, ans[1000002], db;
stack<int> s;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> ut;
    for (int i=2; i<=n; i++) {
        cin >> x;
        while(s.size()>0 && x-ut>=i-s.top()) x-=i-s.top()-1, ut++, s.pop();
        dif=(x-ut)/i;
        ut+=dif, x-=dif*(i-1);
        if (s.size()==0) s.push(0);
        if (x!=ut) s.top()+=x-ut-1, ut++;
        else s.push(i-1);
    }
    for (int i=n; i>=1; i--) {
        if (s.size()>0 && s.top()==i) db++, s.pop();
        ans[i]=ut-n+i+db;
    }
    for (int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
/*
3
1 1 5
*/