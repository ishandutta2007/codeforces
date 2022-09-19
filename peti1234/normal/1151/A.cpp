#include <bits/stdc++.h>

using namespace std;
int n;
string s;
int mini=INT_MAX;
int main()
{
    cin >> n;
    cin >> s;
    for (int i=0; i<n-3; i++) {
        int sum=0;
        int x=s[i]-'A';
        sum+=min(x, 26-x);
        x=abs(s[i+1]-'C');
        sum+=min(x, 26-x);
        x=abs(s[i+2]-'T');
        sum+=min(x, 26-x);
        x=abs(s[i+3]-'G');
        sum+=min(x, 26-x);
        mini=min(mini, sum);
    }
    cout << mini << endl;
    return 0;
}