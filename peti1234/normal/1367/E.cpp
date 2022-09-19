#include <bits/stdc++.h>

using namespace std;
const int c=28;
int w, n, k, db[c], maxi;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, maxi=0;
        for (int i=0; i<c; i++) db[i]=0;
        cin >> s;
        for (int i=0; i<s.size(); i++) db[s[i]-'a']++;
        for (int i=1; i<=k; i++) if (k%i==0) {
            int x=0, y=n+1;
            while(y-x>1) {
                int z=(x+y)/2, cnt=0;
                for (int j=0; j<c; j++) cnt+=db[j]/z;
                if (cnt>=i) x=z;
                else y=z;
            }
            maxi=max(maxi, i*x);
        }
        cout << maxi << "\n";
    }
    return 0;
}