
#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, f, oszt[c], gr[c], ert;
bool pr[c];
bitset<c> jo, b[102];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    pr[1]=1;
    for (int i=2; i<c; i++) {
        if (!pr[i] || !pr[i/oszt[i]]) jo[i]=1;
        if (!pr[i]) {
            for (int j=2*i; j<c; j+=i) oszt[j]=i, pr[j]=1;
        }
    }
    cin >> n >> f;
    jo[f]=0;
    for (int i=0; i<c; i++) {
        int pos=0;
        while(b[pos][i]) pos++;
        gr[i]=pos;
        b[pos] |=jo<<i;
    }
    for (int i=1; i<=n; i++) {
        int a, b, c; cin >> a >> b >> c;
        ert^=gr[b-a-1], ert^=gr[c-b-1];
    }
    if (ert) cout << "Alice\nBob\n";
    else cout << "Bob\nAlice\n";
    return 0;
}