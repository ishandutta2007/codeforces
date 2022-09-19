#include <bits/stdc++.h>

using namespace std;
long long n, m, k, x, y;
long long maxi, mini, sz;
int t;
int main()
{
    cin >> n >> m >> k >> x >> y;
    if (n<3) {
        mini=k/(n*m);
    maxi=mini;
    if (k%(m*n)!=0) {
        maxi ++;
    }
    sz=mini;
    int p=(x-1)*m+y-1;
    if (k%(m*n)>p) {
        sz++;
    }
    cout << maxi << " " << mini << " " << sz << endl;
    return 0;
    }

    mini=k/((n-1)*m*2);
    k=k%((n-1)*m*2);
        maxi=mini*2;
    if (x==1 || x==n) {
        t=1;
        if (x==1) {
            sz=mini;
            if (k>=y) {
                sz++;
            }
        }
        if (x==n) {
            sz=mini;
            if (k>=(n-1)*m+y) {
                sz++;
            }
        }
    }
    else {
        sz=maxi;
    }
    if (k>=n*m) {
        mini ++;
    }
    if (k>m) {
        maxi++;
    }
    if (k>n*m) {
        maxi++;
    }
    int e, u;
    e=(x-1)*m+y-1;

    u=(n-x)*m+y-1;
    if (k<=((n-1)*m) && t==0) {

        if (k>e) {

            sz++;
        }
    }
    if (k>(n-1)*m && t==0) {

        sz++;
        k-=(n-1)*m;
        if (k>u) {
            sz++;
        }
    }
    if (maxi==0) {
        maxi++;
    }
    cout << maxi << " " << mini << " " << sz << endl;
    return 0;
}