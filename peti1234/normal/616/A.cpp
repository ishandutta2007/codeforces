#include <bits/stdc++.h>

using namespace std;
int sa, sb, res;
string a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    sa=a.size(), sb=b.size();
    for (int i=1; i<=max(sa, sb); i++) {
        char aa=(sa>=i ? a[sa-i] : '0'), bb=(sb>=i ? b[sb-i] : '0');
        if (aa>bb) res=1;
        if (bb>aa) res=-1;
    }
    cout << (res==1 ? '>' : res==-1 ? '<' : '=') << "\n";
    return 0;
}