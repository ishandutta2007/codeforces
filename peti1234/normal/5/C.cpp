#include<bits/stdc++.h>

using namespace std;
const int c=2000002;
int n, maxi, db=1, cnt=1e6, ut[c];
string s;
int main()
{
    cin >> s, n=s.size();
    ut[cnt]=1;
    for (int i=0; i<n; i++) {
        if (s[i]=='(') cnt++;
        else {
            ut[cnt]=0;
            cnt--;
            if (ut[cnt]) {
                int x=i-ut[cnt]+2;
                if (x>maxi) maxi=x, db=0;
                if (x==maxi) db++;
            }
        }
        if (!ut[cnt]) ut[cnt]=i+2;
    }
    cout << maxi  << " " << db << "\n";
    return 0;
}