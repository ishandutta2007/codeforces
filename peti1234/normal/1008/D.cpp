#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> v[100001];
int par(int a, int b)
{
    int p=0;
    int x=0;
    int y=0;
    while(x<v[a].size() && y<v[b].size()) {
        if (v[a][x]==v[b][y]) {
            p++;
            x++;
            y++;
        } else {
            if (v[a][x]<v[b][y]) {
                x++;
            } else {
                y++;
            }
        }
    }
    return p;
}
int gcd(int a, int b)
{
    if (a<=b) {
        swap(a, b);
    }
    if (b==0) {
        return a;
    }
    return gcd(b, a%b);
}
int tripla(int a, int b, int c)
{
    int x= gcd(a, b);
    int y=gcd(x, c);
    return v[y].size();
}
int sol(int a, int b, int c, int ab, int ac, int bc, int abc)
{
    int x=a*b*c;
    ab-=abc;
    ac-=abc;
    bc-=abc;
    a-=ab+ac+abc;
    b-=ab+bc+abc;
    c-=ac+bc+abc;
    x-=ab*ac*bc;
    x-=a*(bc+abc)*(bc+abc-1)/2;
    x-=b*(ac+abc)*(ac+abc-1)/2;
    x-=c*(ab+abc)*(ab+abc-1)/2;
    x-=2*(ab*bc*abc+ab*ac*abc+ac*bc*abc);
    x-=(ab)*(ab-1)*(ac+bc+abc)/2;
    x-=(ac)*(ac-1)*(ab+bc+abc)/2;
    x-=(bc)*(bc-1)*(ab+ac+abc)/2;
    x-=(abc)*(ab+ac+bc);
    x-=3*(abc)*(abc-1)*(ab+ac+bc)/2;
    x-=5*(abc)*(abc-1)*(abc-2)/6;
    x-=2*(abc)*(abc-1);
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<=100000; i++) {
        for (int j=i; j<=100000; j+=i) {
            v[j].push_back(i);
        }
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << sol(v[a].size(), v[b].size(), v[c].size(), par(a, b), par(a, c), par(b, c), tripla(a, b, c)) << endl;
    }
    return 0;
}