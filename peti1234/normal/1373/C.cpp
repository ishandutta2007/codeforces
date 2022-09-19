#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        string s;
        cin >> s, n=s.size();
        long long sum=0, mini=0, cnt=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='+') cnt++;
            else cnt--;
            if (cnt<mini) mini=cnt, sum+=i+1;
        }
        cout << sum+n << "\n";
    }
    return 0;
}