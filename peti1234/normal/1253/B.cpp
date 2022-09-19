#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
bool volt[c], van[c];
int n, si;
vector<int> ki, sol;
void rossz()
{
    cout << -1 << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    sol.push_back(0);
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        if (a>0) {
            if (volt[a]) {
                rossz();
                return 0;
            }
            van[a]=true;
            volt[a]=true;
            si++;
            ki.push_back(a);
        } else {
            a*=-1;
            if (!van[a]) {
                rossz();
                return 0;
            }
            van[a]=false;
            si--;
        }
        if (si==0) {
            sol.push_back(i);
            for (int i=0; i<ki.size(); i++) {
                int x=ki[i];
                volt[x]=0;
            }
            ki.clear();
        }
    }
    if (si) {
        rossz();
        return 0;
    }
    int x=sol.size();
    cout << x-1 << "\n";
    for (int i=1; i<x; i++) {
        cout << sol[i]-sol[i-1] << " ";
    }
    return 0;
}