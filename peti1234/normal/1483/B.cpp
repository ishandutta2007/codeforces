#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int w, n, t[c], el[c], kov[c];
bool akt[c];
vector<int> ans, torol;
set<int> s;
bool kis(int a, int b) {
    return (__gcd(t[a], t[b])==1);
}
void kivesz(int a) {
    ans.push_back(a+1);
    el[kov[a]]=el[a], kov[el[a]]=kov[a];
    akt[a]=1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            akt[i]=0;
        }
        ans.clear(), s.clear();
        for (int i=0; i<n; i++) {
            s.insert(i);
            cin >> t[i];
            el[i]=i-1, kov[i]=i+1;
        }
        el[0]=n-1, kov[n-1]=0;
        while (s.size()>0) {
            for (auto i:s) {
                if (!akt[i] && kis(i, kov[i])) {
                    //cout << "ezutan " << i << " " << kov[i] << "\n";
                    kivesz(kov[i]);
                } else {
                    torol.push_back(i);
                }
            }
            for (int i:torol) {
                s.erase(i);
            }
            torol.clear();
        }
        //cout << "valasz: ";
        cout << ans.size() << " ";
        for (int i:ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
1
5
5 9 2 10 15
*/