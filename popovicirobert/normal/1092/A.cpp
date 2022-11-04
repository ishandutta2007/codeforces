#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int t, n, k, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t > 0) {
        t--;
        cin>>n;
        cin>>k;
        for(i=0; i<n; i++)
        {
            cout<< (char) (i % k + 'a');
        }
        cout << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}