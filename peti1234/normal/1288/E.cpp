#include <bits/stdc++.h>
#define lsb(i) ((i) & -(i))
using namespace std;
int n, m;
int maxi[300001];
int el[300001];
int volt[300001];
int van[300001];
int ask(int i)
{
    int sum = 0;
    while (i > 0)
        sum += van[i], i -= lsb(i);
    return sum;
}
int ut(int i)
{
    int sum=0;
    while(i>0) {
        sum+=volt[i], i-=lsb(i);
    }
    return sum;
}
void f(int i)
{
    while(i<=m) volt[i]++, i+=lsb(i);
}
void add(int i)
{
    while(i<=n) van[i]++, i+=lsb(i);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) maxi[i]=i;
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        if (!el[x]) {
            maxi[x]=max(maxi[x], x+ask(n)-ask(x));
            add(x);
            el[x]=i;
        } else {
            maxi[x]=max(maxi[x], i-el[x]-ut(i)+ut(el[x]));
            f(el[x]);
            el[x]=i;
        }
    }
    for (int i=1; i<=n; i++) {
        if (!el[i]) maxi[i]=max(maxi[i], i+ask(n)-ask(i));
        else maxi[i]=max(maxi[i], m+1-el[i]-ut(m)+ut(el[i]));
    }
    for (int i=1; i<=n; i++) {
        if (el[i]) cout << 1 << " ";
        else cout << i << " ";
        cout << maxi[i] << "\n";
    }
    return 0;
}
/*
5 10
1 2 3 4 5 1 2 3 4 5
*/