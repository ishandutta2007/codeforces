#include <bits/stdc++.h>

using namespace std;
int w, n, a, b, sp, an, maxi, cnt;
string s;
int main()
{
    cin >> w;
    while(w--) {
        cin >> a >> b >> s, an=0, sp=0, maxi=0, cnt=0, n=s.size();
        for (int i=0; i<=n; i++) {
            if (i<n && s[i]=='.') cnt++;
            else {
                maxi=max(maxi, cnt);
                if ((cnt>=b && cnt<a) || cnt>=2*b) sp++;
                if (cnt>=a) an++;
                cnt=0;
            }
        }
        if (maxi<a || sp>1 || (sp==1 && maxi<2*b)) cout << "NO\n";
        else {
            bool jo=0;
            if (maxi<=a+2*b-2 && an%2) jo=1;
            if (a<2*b && an%2==0 && maxi>=2*a && maxi<=a+3*b-2) jo=1;
            if (an%2 && a<2*b && maxi>=3*a && maxi<=a+4*b-2) jo=1;
            if (jo) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}