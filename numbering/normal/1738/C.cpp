#include <bits/stdc++.h>
#define int long long
using namespace std;
bool A[505][505]; // A[a][b] a even b odd
bool B[505][505];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i, j;
    for(i=0;i<=100;i++) {
        A[i][0] = true;
        A[0][4*i] = true;
        A[0][4*i+3] = true;
        B[0][4*i+1] = true;
        B[0][4*i+2] = true;
        B[i][0] = false;
        A[1][1] = B[1][1] = true;
    }
    for(int s = 3; s <= 200; s++) {
        for(i=1;i<s;i++) {
            int j = s - i;
            if(j > 100) continue;
            bool a1 = (i==0||j==0||A[i-1][j-1]);
            bool a2 = (i-2<0||A[i-2][j]);
            if(i>0&&a1&&a2) A[i][j] = true;
            bool a3 = (i==0||j==0||B[i-1][j-1]);
            bool a4 = (j-2<0||B[i][j-2]);
            if(j>0&&a3&&a4) A[i][j] = true;
            bool b1 = (i==0||j==0||B[i-1][j-1]);
            bool b2 = (i-2<0||B[i-2][j]);
            if(i>0&&b1&&b2) B[i][j] = true;
            bool b3 = (i==0||j==0||A[i-1][j-1]);
            bool b4 = (j-2<0||A[i][j-2]);
            if(j>0&&b3&&b4) B[i][j] = true;
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int N;
        int cnt1 = 0, cnt2 = 0;
        cin >> N;
        int i, j;
        for(i=0;i<N;i++) {
            int a;
            cin >> a;
            a = abs(a);
            if(a%2==0) cnt1++;
            else cnt2++;
        }
        if(A[cnt1][cnt2]) cout << "Alice\n";
        else cout << "Bob\n";
    }
}