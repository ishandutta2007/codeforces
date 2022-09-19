#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> v;
vector<int> w;
int t[501];
vector<int> q;
int e=0;
int c=2;
int k=0;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        t[i]=x;
        if (x==1) {
            e++;
            w.push_back(i);
        } else {
            c+=x-2;
            v.push_back(i);
        }
    }
    if (e>c) {
        cout << "NO" << endl;
        return 0;
    }
    int c=w.size();
    c=min(2, c);
    cout << "YES" << " "  << v.size()+c-1  << endl << n-1 << endl;
    for (int i=0; i<v.size()-1; i++) {
        cout << v[i] << " " << v[i+1] << endl;
        t[v[i]]--;
        t[v[i+1]]--;
    }
    q.push_back(v.back());
    t[v.back()]--;
    for (int i=1; i<e; i++) {
        while (t[v[k]]==0) {
            k++;
        }
        t[v[k]]--;
        q.push_back(v[k]);
    }
    for (int i=0; i<w.size(); i++) {
        cout << w[i] << " " << q[i] << endl;
    }
    return 0;
}