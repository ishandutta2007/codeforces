#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[100005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    int cnt = 0;
    string c = "abc";
    int i, j;
    for(i=0;i<N-2;i++) {
        bool isK = true;
        for(j=0;j<3;j++) {
            if(s[i+j] != c[j]) isK = false;
        }
        if(isK) cnt++;
    }
    for(i=0;i<Q;i++) {
        int pos;
        char k;
        cin >> pos >> k;
        pos--;
        for(j=max(pos-2,0LL);j<min(N-2,pos+1);j++) {
            bool isK = true;
            for(int m = 0; m < 3; m++) {
                if(s[j+m] != c[m]) isK = false;
            }
            if(isK) cnt--;
        }
        //cout << i+1 << " : " << cnt << '\n';
        s[pos] = k;
        for(j=max(pos-2,0LL);j<min(N-2,pos+1);j++) {
            bool isK = true;
            for(int m = 0; m < 3; m++) {
                if(s[j+m] != c[m]) isK = false;
            }
            if(isK) cnt++;
        }
        cout << cnt << '\n';
    }
}