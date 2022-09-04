#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double dl;
int n;
int a[100], q[1000001];
int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(false);
    cin >> n;
    int k = 0;
    for (int i = 0; i < n; i++){
        char c;
        int x;
        cin >> c >> x;
        if (c == '+')
            a[i] = x, q[x] = 1;
        else{
            a[i] = -x;
            if (q[x] == 0)
                k++;
            else
                q[x] = 0;
        }
    }
    int ans = k, now = k;
    for (int i = 0; i < n; i++)
        if (a[i] > 0){
            now++;
            if (now > ans)
                ans++;
        }
        else
            now--;
    cout << ans;
}