#include <bits/stdc++.h>

using namespace std;
vector<char> c;
int e;
int t[27];
int main()
{
    for (int i=0; i<26; i++) {
        c.push_back('a'+i);
    }
    cin >> e;
    for (int i=1; i<=e; i++) {
        for (int i=0; i<26; i++) {
            t[i]=0;
        }
        string s;
        cin >> s;
        vector<int> q;
        for (int i=0; i<s.size(); i++) {
            int a=s[i]-'a';
            t[a]++;
            if (t[a]==1) {
                q.push_back(a);
            }
        }
        bool p=true;
        sort(q.begin(), q.end());
        if (q.size()==2) {
            if (q[1]-q[0]==1) {
                p=false;
            }
        }
        if (q.size()==3) {
            if (q[2]-q[0]==2) {
                p=false;
            }
        }
        if (q.size()==3 && q[1]-q[0]==1) {
            swap(q[0], q[2]);
        }
        if (!p) {
            cout << "No answer";
        } else {
            for (int i=1; i<q.size(); i+=2) {
                int a=q[i];
                for (int i=0; i<t[a]; i++) {
                    cout << c[a];
                }
            }
            for (int i=0; i<q.size(); i+=2) {
                int a=q[i];
                for (int i=0; i<t[a]; i++) {
                    cout << c[a];
                }
            }
        }
        cout << "\n";
    }
    return 0;
}