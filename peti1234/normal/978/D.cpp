#include <bits/stdc++.h>

using namespace std;
long long n, ans=1e9, t[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int a=t[1]-1; a<=t[1]+1; a++) {
        for (int b=t[2]-1; b<=t[2]+1; b++) {
            long long sum=(abs(t[1]-a)+abs(t[2]-b));
            for (int i=3; i<=n; i++) {
                long long cel=a+(b-a)*(i-1);
                if (abs(t[i]-cel)>1) sum=ans;
                else sum+=abs(t[i]-cel);
            }
            ans=min(ans, sum);
        }
    }
    cout << (ans<=n ? ans : -1) << "\n";
    return 0;
}