#include <bits/stdc++.h>

using namespace std;
int db[32], maxi, n, k, w, f, ans;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k;
        cin >> s;
        ans=n;
        for (int i=0; i<(k+1)/2; i+=1) {
            for (int i=0; i<=27; i++) db[i]=0;
            for (int j=0; j<n; j+=k) {
                int x=s[j+i]-'a'+1, y=s[j+k-i-1]-'a'+1;
                db[x]++;
                if (i!=k/2) db[y]++;
            }
            for (int i=0; i<=27; i++) maxi=max(maxi, db[i]);
            ans-=maxi, maxi=0;
        }
        cout << ans << "\n";
    }
    return 0;
}