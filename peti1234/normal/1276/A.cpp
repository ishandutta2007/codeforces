#include <bits/stdc++.h>

using namespace std;
int q,n;
vector<int> sol;
vector<char> v;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> s;
        n=s.size(), sol.clear(), v.clear();
        for (int i=0; i<n; i++) {
            int si=v.size();
            char x=s[i];
            if (s[i]=='n' && si>0 && v.back()=='o' && i<n-1 && s[i+1]=='e') sol.push_back(i+1);
            else if (s[i]=='o' && si>=2 && v[si-1]=='w' && v[si-2]=='t' && i<n-2 && s[i+1]=='n' && s[i+2]=='e') sol.push_back(i+1);
            else v.push_back(s[i]);
            si++;
            if (si>=3 && v.back()=='o' && v[si-2]=='w' && v[si-3]=='t') {
                sol.push_back(i);
            }
        }
        cout << sol.size() << "\n";
        for (int i=0; i<sol.size(); i++) cout << sol[i] << " ";
        cout << "\n";
    }
    return 0;
}