#include <bits/stdc++.h>

using namespace std;
bool v[5000001];
vector<int> sol;
int ans=0, n, x;
int xo(int a, int b)
{
    int sum=0, p=1;
    while(a>0 || b>0) {
        if (a%2!=b%2) {
            sum+=p;
        }
        p*=2, a/=2, b/=2;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    v[0]=v[x]=1;
    for (int i=1; i<(1<<n); i++) {
        if (!v[i]) {
            sol.push_back(xo(i, ans));
            ans=i;
            v[i]=v[(xo(x, i))]=1;
        }
    }
    cout << sol.size() << "\n";
    for (int i=0; i<sol.size(); i++) {
        cout << sol[i] << " ";
    }
    return 0;
}