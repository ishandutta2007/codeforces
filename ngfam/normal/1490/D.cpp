#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest; cin >> ntest;
    while(ntest--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        
        vector<int> depth(n+2);
        vector<int> parent(n, n+1);

        stack<int> st;
        for(int i = 0; i < n; ++i) {
            while(!st.empty() && a[i] > a[st.top()]) {
                parent[a[st.top()]] = min(parent[a[st.top()]], a[i]);
                st.pop();
            }

            if (!st.empty()) parent[a[i]] = min(parent[a[i]], a[st.top()]);
            st.push(i);
        }

        for(int i = n-1; i >= 1; --i) depth[i] = depth[parent[i]] + 1;
        for(int i = 0; i < n; ++i) cout << depth[a[i]] << " ";
        cout << endl;
    }

    return 0;
}