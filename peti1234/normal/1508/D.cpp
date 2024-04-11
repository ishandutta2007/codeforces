#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int n, t[c], pos, ki[c];
vector<int> sor;
long long x[c], y[c];
bool v[c];
vector<pair<int, int> > ans;
void dfs(int a) {
    v[a]=true;
    if (!v[t[a]]) {
        ki[t[a]]=ki[a];
        dfs(t[a]);
    }
}
void add(int a, int b) {
    ans.push_back({a, b});
    swap(t[a], t[b]);
}
bool f(int a, int b) {
    long long s=(x[a]-x[pos])*(y[b]-y[pos])-(x[b]-x[pos])*(y[a]-y[pos]);
    return (s>0);
}
int holvan(int a) {
    if (ki[a]==a) {
        return a;
    }
    return ki[a]=holvan(ki[a]);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    ki[a]=b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i] >> t[i];
        if (t[i]!=i && (!pos || x[i]<x[pos])) {
            pos=i;
        }
    }
    if (!pos) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            ki[i]=i;
            dfs(i);
        }
        if (t[i]!=i && i!=pos) {
            sor.push_back(i);
        }
    }
    //cout << pos << "\n";
    sort(sor.begin(), sor.end(), f);
    //cout << "sorrend ";
    /*
    for (auto x:sor) {
        cout << x << " ";
    }
    cout << "\n";
    */
    for (int i=1; i<sor.size(); i++) {
        int a=sor[i], b=sor[i-1];
        if (holvan(a)!=holvan(b)) {
            unio(a, b);
            add(a, b);
        }
    }
    for (int i=0; i<sor.size(); i++) {
        add(pos, t[pos]);
    }
    cout << ans.size() << "\n";
    for (auto x:ans) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}
/*
5
-1 -2 2
3 0 5
1 3 4
4 -3 3
5 2 1
*/