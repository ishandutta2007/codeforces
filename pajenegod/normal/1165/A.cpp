#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    
    int n,x,y;
    cin >> n >> x >> y;

    vector<int> A(n);

    char c;
    for (auto &a:A)
    {
        cin >> c;
        a = c - '0';
    }
    
    int cost = 0;
    for (int i=n-1-x + 1; i<n; ++i)
        cost += A[i];
    
    if (A[n-1-y])
        cost -= 1;
    else
        cost += 1;

    cout << cost << "\n";
}