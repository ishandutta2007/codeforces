#include <bits/stdc++.h>
#define ll long long


using namespace std;



int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    char ch1;
    cin >> ch1;
    int cnt1 = 0, cnt2 = 0;
    for(i = 1; i < n; i++) {
        char ch2;
        cin >> ch2;
        if(ch1 == 'S' && ch2 == 'F')
            cnt1++;
        else if(ch1 != ch2)
            cnt2++;
        ch1 = ch2;
    }
    if(cnt1 > cnt2)
        cout << "YES";
    else
        cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}