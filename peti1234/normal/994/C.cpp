#include <bits/stdc++.h>

using namespace std;
long long x[11];
long long y[11];
int k(int a, int b, int c)
{
    int f=(x[c]-x[a])*(y[b]-y[a])-(y[c]-y[a])*(x[b]-x[a]);
    if (f<0) {
        return -1;
    }
    return f>0;
}
vector<int> v;
vector<int> w;
bool benn(int i)
{
    bool x=false, y=false;
    int p=k(1, 2, i);
    if (p==1) {
        x=true;
    }
    if (p==-1) {
        y=true;
    }
    p=k(2, 3, i);
    if (p==1) {
        x=true;
    }
    if (p==-1) {
        y=true;
    }
    p=k(3, 4, i);
    if (p==1) {
        x=true;
    }
    if (p==-1) {
        y=true;
    }
    p=k(4, 1, i);
    if (p==1) {
        x=true;
    }
    if (p==-1) {
        y=true;
    }
    return !x||!y;
}
bool bennn(int i)
{
    bool x=false, y=false;
    int p=k(5, 6, i);
    if (p==1) {
        x=true;
    }
    if (p==-1) {
        y=true;
    }
    p=k(6, 7, i);
    if (p==1) {
        x=true;
    }
    if (p==-1) {
        y=true;
    }
    p=k(7, 8, i);
    if (p==1) {
        x=true;
    }
    if (p==-1) {
        y=true;
    }
    p=k(8, 5, i);
    if (p==1) {
        x=true;
    }
    if (p==-1) {
        y=true;
    }
    return !x||!y;
}
bool egyenes(int a, int b, int c, int d)
{
    int x=k(a, b, c)+k(a, b, d);
    int y=k(c, d, a)+k(c, d, b);
    if (x==y && x==0) {
        return true;
    }
    return false;
}
int main()
{
    for (int i=1; i<=8; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i=5; i<=8; i++) {
        if (benn(i)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    for (int i=1; i<=4; i++) {
        if (bennn(i)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    w.push_back(5);
    w.push_back(6);
    w.push_back(7);
    w.push_back(8);
    w.push_back(5);
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (egyenes(v[i], v[i+1], w[j], w[j+1])) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
/*
0 0 0 1 1 1 1 0
1 1 2 2 3 1 0 2
/*11 10
1 2 3 4 5 6 7 8 9 10 11
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000*/