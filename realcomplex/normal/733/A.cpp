#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long mx;
int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    string s;
    long l = 0;
    cin >> s;
    long ac = 1;
    for(long j = 0;j<s.size();j++){
        if(s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U' || s[j] == 'Y'){
            mx = max(mx,ac-l);
            l = ac;
        }
        ac++;
    }
    mx = max(mx,long((s.size()+1)-l));
    cout << mx;
    return 0;
}