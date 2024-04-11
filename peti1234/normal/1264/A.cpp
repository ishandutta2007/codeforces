#include <bits/stdc++.h>

using namespace std;
int t[1000001];
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            t[x]++;
            if (v.size()==0 || v.back()!=x) {
                v.push_back(x);
            }
        }
        int g=0, s=0, b=0;
        g=t[v[0]];
        int k=1;
        for (int i=1; i<v.size(); i++) {
            s+=t[v[i]];
            k=i+1;
            if (s>g) {
                break;
            }
        }
        for (int i=k; i<v.size(); i++) {
            int p=t[v[i]];
            if (2*(g+s+b+p)<=n) {
                b+=p;
            } else {
                break;
            }
        }
        if (g>=b || 2*(g+s+b)>n) g=0, s=0, b=0;
        cout << g << " " << s << " " << b << "\n";
        for (int i=0; i<v.size(); i++) {
            t[v[i]]=0;
        }
        v.clear();
    }
    return 0;
}
/*
1
12
5 4 4 3 2 2 1 1 1 1 1 1
*/