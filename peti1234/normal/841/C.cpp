#include <bits/stdc++.h>

using namespace std;
int n;
int a[200001];
int b[200001];
int mb[200001];
map <int, int> k;
vector<int> t[200001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
        mb[i]=b[i];
    }
    sort(b+1, b+n+1);
    //reverse(b+1, b+n+1);
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);
    int x=1;
    for (int i=1; i<=n; i++) {
        if (b[i]!=b[i-1]) {
            k[b[i]]=x;
            x++;
        }
    }
    for (int i=1; i<=n; i++) {
        t[k[mb[i]]].push_back(i);
    }
    int y=1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<t[i].size(); j++) {
            mb[y]=t[i][j];
            y++;
        }
    }
    for (int i=1; i<=n; i++) {
        b[mb[i]]=a[i];
    }
    for (int i=1; i<=n; i++) {
        cout << b[i] << " ";
    }
    return 0;
}