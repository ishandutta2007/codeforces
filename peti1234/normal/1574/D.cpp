#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> sz[10];
set<vector<int> > s, s2;
priority_queue<pair<int, vector<int> > > q;
int main()
{
    int sum=0;
    vector<int> st;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        for (int j=0; j<x; j++) {
            int y;
            cin >> y;
            sz[i].push_back(y);
        }
        sum+=sz[i].back();
        st.push_back(sz[i].size());
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        vector<int> f;
        for (int j=0; j<n; j++) {
            int x;
            cin >> x;
            f.push_back(x);
        }
        s.insert(f);
    }
    /*cout << "vege " << s.size() << "\n";
    for (auto v:s) {
        for (auto x:v) {
            cout << x << " ";
        }
        cout << "\n";
    }*/
    q.push({sum, st});
    while (q.size()>0) {
        //cout << "proba\n";
        vector<int> v=q.top().second;
        /*for (auto x:v) {
            cout << x << " ";
        }
        cout << "\n";*/
        int ert=q.top().first;
        q.pop();
        if (s.find(v)==s.end()) {
            //cout << "siker\n";
            for (auto x:v) {
                cout << x << " ";
            }
            cout << "\n";
            return 0;
        }
        if (s2.find(v)==s2.end()) {
            s2.insert(v);
            for (int i=0; i<n; i++) {
                if (v[i]>1) {
                    vector<int> uj=v;
                    uj[i]--;
                    int s2=ert-sz[i][uj[i]]+sz[i][uj[i]-1];
                    q.push({s2, uj});
                }
            }
        }
    }
    return 0;
}