#include <bits/stdc++.h>

using namespace std;
string s;
int n, k;
vector<int> v[27];
int main()
{
    cin >> n >> k;
    cin >> s;
    int x=1;
    for (int i=1; i<s.size(); i++) {
        if (s[i]==s[i-1]) {
            x++;
        } else {
            int c=s[i-1]-'a';
            v[c].push_back(x);
            x=1;
        }
    }
    int c=s[n-1]-'a';
    v[c].push_back(x);
    int sum=0;
    for (int j=0; j<26; j++) {
        int maxi=0;
        for (int i=0; i<v[j].size(); i++) {
            maxi+=v[j][i]/k;
        }
        sum=max(sum, maxi);
    }
    cout << sum << endl;
    return 0;
}