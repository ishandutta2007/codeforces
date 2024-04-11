#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define ll long long
#define X first
#define Y second
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY
#define LIMIT  1000010

using namespace std;

stack <int> s;
int n, t;
int a[LIMIT];

void Tim(int u)
{
    stack <int> t;
    t.push(u);
    while(!t.empty())
    {
        if(s.empty())
        {
            cout << "NO";
            exit(0);
        }
        if(a[s.top()] + a[t.top()] == 0)
            t.pop();
        else
        {
            a[s.top()] *= -1;
            t.push(s.top());
        }
        s.pop();
    }
}

int main()
{
    //filein, fileout;
    Ri(n);
    FOR(i, 1, n) Ri(a[i]);
    Ri(t);
    FOR(i, 1, t)
    {
        int x;
        Ri(x);
        a[x] *= -1;
    }
    FOR(i, 1, n)
    if(a[i] < 0) Tim(i);
    else s.push(i);
    while(!s.empty())
    {
        int x = s.top();
        a[x] *= -1;
        s.pop();
        Tim(x);
    }
    cout << "YES" << endl;
    FOR(i, 1, n) cout << a[i] << " ";
    return 0;
}